QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlefieldcoords.cpp \
    cabstractbattlefield.cpp \
    cabstractbattlefieldlabel.cpp \
    cbattlefieldbutton.cpp \
    cbattlefieldgrid.cpp \
    ccomputerbattlefield.cpp \
    ccomputerbattlefieldlabel.cpp \
    ccomputerplayer.cpp \
    cgamemanagement.cpp \
    cplayerbattlefield.cpp \
    cplayerbattlefieldlabel.cpp \
    cplayerplacement.cpp \
    cshipatcoords.cpp \
    cshipvector.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    battlefieldcoords.h \
    cabstractbattlefield.h \
    cabstractbattlefieldlabel.h \
    cbattlefieldbutton.h \
    cbattlefieldgrid.h \
    cbattlefieldgriditerator.h \
    cbattlefieldgridregister.h \
    ccomputerbattlefield.h \
    ccomputerbattlefieldlabel.h \
    ccomputerplayer.h \
    cgamemanagement.h \
    cplayerbattlefield.h \
    cplayerbattlefieldlabel.h \
    cplayerplacement.h \
    cshipatcoords.h \
    cshipvector.h \
    mainwindow.h \
    randomizer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
