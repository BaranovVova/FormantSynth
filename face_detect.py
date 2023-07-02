# -*- coding: utf-8 -*-
from typing import Tuple, Union
import imutils
import cv2
import numpy as np
import datetime
import time
import random
import math
import numpy as np
import cv2
import pyautogui
import os
from threading import Thread
import PIL
from PIL import Image
from PIL import ImageFilter
from PIL import ImageDraw

#import pywintypes, win32file, win32con # pip install pypiwin32
#import sounddevice as sd
#from scipy.io.wavfile import write
#import mediapipe as mp
#from mediapipe.tasks import python
#from mediapipe.tasks.python import vision
import numpy as np
import tensorflow as tf; 
print(tf.config.list_physical_devices('GPU'))
from fdlite.face_landmark import FaceLandmark, face_detection_to_roi 
from fdlite import FaceDetection, FaceDetectionModel
from fdlite.render import Colors, detections_to_render_data, render_to_image 
from PIL import Image

def warpPerspVFX(frame):
    x = 0
    y = 0
    w = frame.shape[1]
    h = frame.shape[0]
    corners = [[x,y], [w, y], [w, h], [x, h]]    
    x = x + random.randint(1,10)
    w = w + random.randint(-100,100)
    new = np.float32([[x,y], [w, y], [w, h], [x, h]]   )
    M = cv2.getPerspectiveTransform(np.float32(corners), new)
    img = cv2.warpPerspective(frame, M, ( frame.shape[1], frame.shape[0]))
    return img


src = 0
stream = cv2.VideoCapture(src)
width = 800
height = 600
stream.set(cv2.CAP_PROP_FRAME_WIDTH, width)
stream.set(cv2.CAP_PROP_FRAME_HEIGHT, height)


# when using an image as mask only the alpha channel is important
solid_fill =  (50,50,50,255) 

def create_rounded_rectangle_mask(rectangle, radius):
    # create mask image. all pixels set to translucent
    i = Image.new("RGBA",rectangle.size,(0,0,0,0))

    # create corner
    corner = Image.new('RGBA', (radius, radius), (0, 0, 0, 0))
    draw = ImageDraw.Draw(corner)
    # added the fill = .. you only drew a line, no fill
    draw.pieslice((0, 0, radius * 2, radius * 2), 180, 270, fill = solid_fill)

    # max_x, max_y
    mx,my = rectangle.size

    # paste corner rotated as needed
    # use corners alpha channel as mask

    i.paste(corner, (0, 0), corner)
    i.paste(corner.rotate(90), (0, my - radius),corner.rotate(90))
    i.paste(corner.rotate(180), (mx - radius,   my - radius),corner.rotate(180))
    i.paste(corner.rotate(270), (mx - radius, 0),corner.rotate(270))

    # draw both inner rects
    draw = ImageDraw.Draw(i)
    draw.rectangle( [(radius,0),(mx-radius,my)],fill=solid_fill)
    draw.rectangle( [(0,radius),(mx,my-radius)],fill=solid_fill)

    return i

# LOOP!
while True:
    t0 = time.time_ns()
    
    #video_getter.get()
    
 #   frame = video_getter.frame
    (grabbed, frame0) = stream.read()   
    #time.sleep(0.1)
    if grabbed:
        # STEP 2: Create an FaceDetector object.
        #cv2.imshow(rgb_annotated_image)
        #image = Image.open('Screenshot 2023-06-21 17-05-55.png')
        im_pil = Image.fromarray(frame0)
        detect_faces = FaceDetection(model_type=FaceDetectionModel.BACK_CAMERA)
        face_landmarks = FaceLandmark()
        faces = detect_faces(im_pil)
     
        #print('test '.format(roi[1]))
        
 
        
        if not len(faces):
            print('no faces detected :(')
        else:
            roi = face_detection_to_roi(faces[0], (im_pil.width,im_pil.height))
            landmarks = face_landmarks(im_pil, roi)
            
            render_data = detections_to_render_data(faces, bounds_color=Colors.GREEN)
            #render_to_image(render_data, im_pil)                     
            x, y = int(faces[0].bbox.xmin * im_pil.width), int(faces[0].bbox.ymin * im_pil.height) 
            w=int((faces[0].bbox.xmax - faces[0].bbox.xmin)*im_pil.width)
            print("w={}".format(w))
            if w < 50: 
                w = 50
            #x = 10
            #y = 10
            radius = 25
            cropped_img = im_pil.crop((x-30, y-30, x+int(w), y+int(w)))
            # the filter removes the alpha, you need to add it again by converting to RGBA
            blurred_img = cropped_img.filter(ImageFilter.GaussianBlur(20),).convert("RGBA")
            # paste blurred, uses alphachannel of create_rounded_rectangle_mask() as mask 
            # only those parts of the mask that have a non-zero alpha gets pasted
            im_pil.paste(blurred_img, (x-30, y-30), create_rounded_rectangle_mask(cropped_img,radius))
            
            
            open_cv_image = np.array(im_pil)
            
          

            for lm in landmarks:
                x, y = int(lm.x * im_pil.width), int(lm.y * im_pil.height)
                print('x,y={}{}'.format(x,y))
                cv2.rectangle(open_cv_image, (x, y), (x+1, y+1), (255,0,0), 1)
            print('test {}'.format(roi.x_center))
            
            print(landmarks)
            cv2.imshow("frame", open_cv_image)
            
        
        #cv2.imshow("frame", frame0)
    print('frame')
    ch = cv2.waitKey(1)
    if ch & 0xFF == ord('q'):
        break;
   
    
    


# Cleanup when closed
stream.close()
cv2.waitKey(0)
cv2.destroyAllWindows()


