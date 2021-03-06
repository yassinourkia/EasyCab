#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T15:23:41
#
#-------------------------------------------------

QT       += core sql gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyCab
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
    login.cpp \
    connect.cpp \
    utilisateur.cpp \
    patient.cpp \
    patientmanagement.cpp \
    rdvform.cpp \
    rdv.cpp \
    listrdv.cpp \
    formstate.cpp \
    state.cpp \
    staterdv.cpp \
    secretaire.cpp \
    secretaryinterface.cpp \
    doctordashboard.cpp \
    medecin.cpp \
    logindoctor.cpp \
    listpatients.cpp \
    accueil.cpp \
    listrdvsec.cpp

HEADERS += \
    login.h \
    connect.h \
    utilisateur.h \
    patient.h \
    patientmanagement.h \
    rdvform.h \
    rdv.h \
    listrdv.h \
    formstate.h \
    state.h \
    staterdv.h \
    secretaire.h \
    secretaryinterface.h \
    doctordashboard.h \
    medecin.h \
    logindoctor.h \
    listpatients.h \
    accueil.h \
    listrdvsec.h

FORMS += \
    login.ui \
    patientmanagement.ui \
    rdvform.ui \
    listrdv.ui \
    formstate.ui \
    staterdv.ui \
    secretaryinterface.ui \
    doctordashboard.ui \
    logindoctor.ui \
    listpatients.ui \
    accueil.ui \
    listrdvsec.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

