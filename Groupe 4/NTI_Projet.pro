QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addition.cpp \
    constante.cpp \
    division.cpp \
    expression.cpp \
    grapheur2dcontroller.cpp \
    grapheur2dmodel.cpp \
    grapheur2dview.cpp \
    main.cpp \
    mainwindow.cpp \
    multiplication.cpp \
    operateur.cpp \
    soustraction.cpp \
    variable.cpp

HEADERS += \
    addition.h \
    constante.h \
    division.h \
    expression.h \
    grapheur2dcontroller.h \
    grapheur2dmodel.h \
    grapheur2dview.h \
    mainwindow.h \
    multiplication.h \
    operateur.h \
    soustraction.h \
    variable.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
