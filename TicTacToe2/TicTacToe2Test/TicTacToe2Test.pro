
QT += testlib
CONFIG += c++2a console testcase
CONFIG -= app_bundle

INCLUDEPATH += ../TicTacToe2


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../TicTacToe2/playfieldcoords.cpp \
        ../TicTacToe2/playfield.cpp \
        ../TicTacToe2/computerenemy.cpp \
        playfieldcoords_test.cpp \
        playfield_test.cpp \
        computerenemy_test.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../TicTacToe2/playfieldcoords.h \
    ../TicTacToe2/playfield.h \
    ../TicTacToe2/computerenemy.h \
    playfieldcoords_test.h \
    playfield_test.h \
    computerenemy_test.h \
    testdefines.h

