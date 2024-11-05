QT       += core gui
QT       += opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# CONFIG += staticlib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fpgainterface.cpp \
    glvideowidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    fpgainterface.h \
    glvideowidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += "$$(setupapi)/include/10.0.26100.0/um"
LIBS += -L"$$(setupapi)/lib/10.0.26100.0/um/x64"\
    -lSetupAPI\
    -lUser32

INCLUDEPATH += "$$(useful)/include"
LIBS += -L"$$(useful)/lib/x64"\
    -llegacy_stdio_definitions

# INCLUDEPATH += "$$(EZUSB_DEV_DIR)/include"
# contains(QMAKE_TARGET.arch, x86_64) {
#     LIBS += -L"$$(EZUSB_DEV_DIR)/lib/64"
# } else {
#     LIBS += -L"$$(EZUSB_DEV_DIR)/lib/x86"
# }

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    111.yuv

RESOURCES += \
    resources.qrc

unix|win32: LIBS += -L$$PWD/../../2/WPIMQP/ezusb/lib/x64/ -lCyAPI

INCLUDEPATH += $$PWD/../../2/WPIMQP/ezusb/include
DEPENDPATH += $$PWD/../../2/WPIMQP/ezusb/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../2/WPIMQP/ezusb/lib/x64/CyAPI.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../2/WPIMQP/ezusb/lib/x64/libCyAPI.a
