include(openglwindow.pri)

QT += gui widgets
SOURCES += \
    bigbangscene.cpp \
    blackhole.cpp \
    blastsphere.cpp \
    common.cpp \
    main.cpp \
    particle_render.cpp \
    ring3d.cpp \
    textform.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/openglwindow
INSTALLS += target

FORMS += \
    textform.ui

HEADERS += \
    Scene.h \
    bigbangscene.h \
    blackhole.h \
    blastsphere.h \
    common.h \
    particle.h \
    particle_render.h \
    ring3d.h \
    textform.h

RESOURCES += \
    res.qrc

INCLUDEPATH += C:\\Projects\\cube\\openglwindow\\ThirdParty\\ttmath
INCLUDEPATH += C:\\Projects\\freeglut-master\\include
DEPENDPATH += C:\\Projects\\freeglut-master\\include

win32: LIBS += -L$$PWD/../../build-freeglut-master-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/lib/ -lfreeglut_static
win32: LIBS += -L$$PWD/../../build-freeglut-master-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/lib/ -lfreeglut.dll

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../build-freeglut-master-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/lib/freeglut_static.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../build-freeglut-master-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/lib/libfreeglut_static.a
