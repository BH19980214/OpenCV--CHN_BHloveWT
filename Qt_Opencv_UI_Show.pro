QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autothread.cpp \
    camerainterface.cpp \
    choose_number.cpp \
    convert_mat_qimage.cpp \
    main.cpp \
    mainwindow.cpp \
    mycamera.cpp \
    mylabel.cpp \
    mymodbus.cpp \
    mythread.cpp \
    standardization_window.cpp \
    txtname.cpp

HEADERS += \
    autothread.h \
    camerainterface.h \
    choose_number.h \
    convert_mat_qimage.h \
    mainwindow.h \
    mycamera.h \
    mylabel.h \
    mymodbus.h \
    mythread.h \
    standardization_window.h \
    txtname.h

FORMS += \
    choose_number.ui \
    mainwindow.ui \
    standardization_window.ui \
    txtname.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../study/opencv-4.5.1-vc14_vc15/opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../study/opencv-4.5.1-vc14_vc15/opencv/build/x64/vc15/lib/ -lopencv_world451d
else:unix: LIBS += -L$$PWD/../../../study/opencv-4.5.1-vc14_vc15/opencv/build/x64/vc15/lib/ -lopencv_world451

INCLUDEPATH += $$PWD/../../../study/opencv-4.5.1-vc14_vc15/opencv/build/include
DEPENDPATH += $$PWD/../../../study/opencv-4.5.1-vc14_vc15/opencv/build/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/contours_find/x64/release/ -lProject3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/contours_find/x64/debug/ -lProject3
else:unix: LIBS += -L$$PWD/contours_find/x64/ -lProject3

INCLUDEPATH += $$PWD/contours_find/x64/Debug
DEPENDPATH += $$PWD/contours_find/x64/Debug


LIBS += -L$$PWD/Hik_Libs/ -lMvCameraControl
INCLUDEPATH += $$PWD/Hik_Includes
DEPENDPATH += $$PWD/Hik_Includes

QT += serialbus serialport widgets


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/number_Find_DLL/x64/release/ -lnumber_Find_DLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/number_Find_DLL/x64/debug/ -lnumber_Find_DLL
else:unix: LIBS += -L$$PWD/number_Find_DLL/x64/ -lnumber_Find_DLL

INCLUDEPATH += $$PWD/number_Find_DLL/x64/Debug
DEPENDPATH += $$PWD/number_Find_DLL/x64/Debug
