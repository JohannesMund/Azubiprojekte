QT -= gui

QT += testlib
CONFIG += c++11 console testcase
CONFIG -= app_bundle

INCLUDEPATH += ../Rechner


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../Rechner/calculatornumber.cpp \
        ../Rechner/result.cpp \
        calculatornumber_test.cpp \
        result_test.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../Rechner/calculatornumber.h \
    ../Rechner/result.h \
    calculatornumber_test.h \
    result_test.h

