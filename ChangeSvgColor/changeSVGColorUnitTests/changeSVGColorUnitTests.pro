QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../changeSVGColor


HEADERS += ../changeSVGColor/change.h
HEADERS += ../changeSVGColor/search.h

SOURCES +=  tst_testchange.cpp\
            ../changeSVGColor/change.cpp
SOURCES += tst_testchange.cpp\
            ../changeSVGColor/search.cpp
