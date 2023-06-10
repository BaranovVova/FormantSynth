
// Set default precision to medium
varying lowp vec4 col;
in vec2 gl_FragCoord;
uniform highp int pipe;
uniform sampler2D texture;
uniform sampler2D vel_texture;
varying vec2 v_texcoord;
varying vec2 v_velocitiesAttr;

//! [0]
void main()
{
    vec4 tex_col = texture2D(texture, v_texcoord);
    vec4 vel_col = texture2D(vel_texture, v_texcoord);

    // Get the current pixel's motion vector.
    vec2 motionVector;
    if( pipe == 2)
    {
        // unpack the velocities
        if(vel_col.g < 0.001)
            motionVector.x = -vel_col.r;
        else
            motionVector.x = vel_col.r;
        if(vel_col.a < 0.001)
            motionVector.y = -vel_col.b;
        else
            motionVector.y = vel_col.b;


    }
     motionVector.x =  0.0005 * motionVector.x;
     motionVector.y =  0.0005 * motionVector.y;
     //motionVector = vec2(0.005, 0.005);
    //vec2 motionVector = vec2(1, 1);

     float blurRadius = 30;
     //gl_PointSize = 12.0;

     // Calculate the number of samples to take.
     int numSamples = 1 + blurRadius * 2;

     // Blur the current pixel by sampling from a range of pixels around it.
     vec4 color;

     for (int i = -blurRadius; i <= blurRadius; i++) {
       color += texture2D(texture, v_texcoord.xy + motionVector * i) * (1.0 / numSamples);
     }
     color = 1.0 * color;

    // Set fragment color from texture
    if( pipe == 0)
      gl_FragColor = col;

    if( pipe == 1)
    {
        if(v_velocitiesAttr.x > 0)
          color.g = 1;
        else
           color.g = 0;
        color.r = abs(v_velocitiesAttr.x);

        if(v_velocitiesAttr.y > 0)
          color.a = 1;
        else
           color.a = 0;
        color.b = abs(v_velocitiesAttr.y);
        //color.a = 1;

        gl_FragColor = color;

    }

    if( pipe == 2)
    {
      gl_FragColor = color; //vec4(vel_col.x,vel_col.y,1,1);      
      //gl_FragColor = vec4(1,1,0,1);
    }
    //gl_FragColor.r = gl_PointCoord.x;
}
