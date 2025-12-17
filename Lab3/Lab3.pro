QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddoctorwidget.cpp \
    addpatientwidget.cpp \
    addsubwidget.cpp \
    choosewidget.cpp \
    deldocwidget.cpp \
    delpatientwidget.cpp \
    delsubwidget.cpp \
    docwidget.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwideget.cpp \
    modifydocwidget.cpp \
    modifypatwidget.cpp \
    modifysubwidget.cpp \
    patientwidget.cpp \
    singletodb.cpp \
    subwidget.cpp

HEADERS += \
    adddoctorwidget.h \
    addpatientwidget.h \
    addsubwidget.h \
    choosewidget.h \
    deldocwidget.h \
    delpatientwidget.h \
    delsubwidget.h \
    docwidget.h \
    loginwidget.h \
    mainwideget.h \
    modifydocwidget.h \
    modifypatwidget.h \
    modifysubwidget.h \
    patientwidget.h \
    singletodb.h \
    subwidget.h

FORMS += \
    adddoctorwidget.ui \
    addpatientwidget.ui \
    addsubwidget.ui \
    choosewidget.ui \
    deldocwidget.ui \
    delpatientwidget.ui \
    delsubwidget.ui \
    docwidget.ui \
    loginwidget.ui \
    mainwideget.ui \
    modifydocwidget.ui \
    modifypatwidget.ui \
    modifysubwidget.ui \
    patientwidget.ui \
    subwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
