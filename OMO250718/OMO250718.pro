#-------------------------------------------------
#
# Project created by QtCreator 2025-11-23T10:44:36
#
#-------------------------------------------------

QT       += core gui serialport multimedia serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OMO250718
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    VIEW/settingwidget.cpp \
    VIEW/myitem.cpp \
    VIEW/myview.cpp \
    VIEW/linechart.cpp \
    VIEW/barchart.cpp \
    VIEW/mainwidget.cpp \
    DATA/singletondb.cpp \
    CONTROLLER/envidatacontroller.cpp \
    MODEL/envidatamodel.cpp \
    THREAD/opencamera.cpp \
    TOOL/encodetoh264.cpp \
    THREAD/playthread.cpp \
    VIEW/vedioplayer.cpp \
    TOOL/trancecode.cpp

HEADERS += \
        mainwindow.h \
    VIEW/settingwidget.h \
    VIEW/myitem.h \
    VIEW/myview.h \
    VIEW/linechart.h \
    VIEW/mainwidget.h \
    DATA/singletondb.h \
    CONTROLLER/envidatacontroller.h \
    MODEL/envidatamodel.h \
    VIEW/barchart.h \
    THREAD/opencamera.h \
    TOOL/encodetoh264.h \
    THREAD/playthread.h \
    VIEW/vedioplayer.h \
    TOOL/trancecode.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/ffmpeglib/include
LIBS += $$PWD/ffmpeglib/lib/avcodec.lib  \
        $$PWD/ffmpeglib/lib/avdevice.lib  \
        $$PWD/ffmpeglib/lib/avfilter.lib  \
        $$PWD/ffmpeglib/lib/avformat.lib  \
        $$PWD/ffmpeglib/lib/avutil.lib  \
        $$PWD/ffmpeglib/lib/swresample.lib  \
        $$PWD/ffmpeglib/lib/swscale.lib  \
        $$PWD/lib/sqlite3.lib
DESTDIR = bin

RESOURCES += \
    resource.qrc

CONFIG += c++11

DISTFILES +=
