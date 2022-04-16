
QT += testlib
CONFIG += c++11 console testcase
CONFIG -= app_bundle

INCLUDEPATH += ../TicTacToe2


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../TicTacToe2/playfieldcoords.cpp \
        ../TicTacToe2/playfield.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../TicTacToe2/playfieldcoords.h \
    ../TicTacToe2/playfield.h \
    playfieldcoords_test.h \
    playfield_test.h \
    result_test.h

