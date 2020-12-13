QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accevents.cpp \
    acctype.cpp \
    clientadder.cpp \
    deposit.cpp \
    main.cpp \
    login.cpp \
    options.cpp \
    saldoform.cpp \
    varsingleton.cpp \
    withdraw2.cpp

HEADERS += \
    accevents.h \
    acctype.h \
    clientadder.h \
    deposit.h \
    login.h \
    options.h \
    saldoform.h \
    varsingleton.h \
    withdraw2.h

FORMS += \
    accevents.ui \
    acctype.ui \
    clientadder.ui \
    deposit.ui \
    login.ui \
    options.ui \
    saldoform.ui \
    withdraw2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += network

