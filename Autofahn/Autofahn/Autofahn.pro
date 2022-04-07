TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
        inc/ \
        inc/fahrzeuge \
        inc/personen \
        inc/drinks


SOURCES += \
        src/drinks/chexensuppe.cpp \
        src/drinks/cbier.cpp \
        src/drinks/cdrink.cpp \
        src/drinks/cdrinkfactory.cpp \
        src/drinks/cenergy.cpp \
        src/drinks/cmineralwasser.cpp \
        src/drinks/cschnaps.cpp \
        src/fahrzeuge/cauto.cpp \
        src/fahrzeuge/cfahrzeug.cpp \
        src/fahrzeuge/cpanzer.cpp \
        src/personen/channes.cpp \
        src/personen/cperson.cpp \
        src/personen/chansdieter.cpp \
        src/main.cpp

HEADERS += \
    inc/drinks/cbier.h \
    inc/drinks/cdrink.h \
    inc/drinks/cdrinkfactory.h \
    inc/drinks/cenergy.h \
    inc/drinks/chexensuppe.h \
    inc/drinks/cmineralwasser.h \
    inc/drinks/cschnaps.h \
    inc/fahrzeuge/cauto.h \
    inc/fahrzeuge/cfahrzeug.h \
    inc/fahrzeuge/cpanzer.h \
    inc/personen/channes.h \
    inc/personen/cperson.h \
    inc/personen/chansdieter.h \
