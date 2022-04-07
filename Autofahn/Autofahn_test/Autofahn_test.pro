QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
        ../Autofahn/inc/ \
        ../Autofahn/inc/fahrzeuge \
        ../Autofahn/inc/personen \
        ../Autofahn/inc/drinks



HEADERS += \
    ../Autofahn/inc/personen/cperson.h \
    ../Autofahn/inc/personen/chansdieter.h \
    ../Autofahn/inc/drinks/cbier.h \
    ../Autofahn/inc/drinks/cdrink.h \
    ../Autofahn/inc/drinks/cdrinkfactory.h \
    ../Autofahn/inc/drinks/cenergy.h \
    ../Autofahn/inc/drinks/chexensuppe.h \
    ../Autofahn/inc/drinks/cmineralwasser.h \
    ../Autofahn/inc/drinks/cschnaps.h \
    tst_testdrinksfactory.h \
    tst_testhansdieter.h \


SOURCES +=  \
    main.cpp \
    tst_testdrinksfactory.cpp \
    tst_testhansdieter.cpp \
    ../Autofahn/src/personen/cperson.cpp \
    ../Autofahn/src/personen/chansdieter.cpp \
    ../Autofahn/src/drinks/chexensuppe.cpp \
    ../Autofahn/src/drinks/cbier.cpp \
    ../Autofahn/src/drinks/cdrink.cpp \
    ../Autofahn/src/drinks/cdrinkfactory.cpp \
    ../Autofahn/src/drinks/cenergy.cpp \
    ../Autofahn/src/drinks/cmineralwasser.cpp \
    ../Autofahn/src/drinks/cschnaps.cpp

