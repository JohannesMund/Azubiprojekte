set(BATTLESHIP_SOURCES
    battlefieldcoords.cpp
    cabstractbattlefield.cpp
    cabstractbattlefieldlabel.cpp
    cbattlefieldbutton.cpp
    cbattlefieldgrid.cpp
    ccomputerbattlefield.cpp
    ccomputerbattlefieldlabel.cpp
    ccomputerplayer.cpp
    cgamemanagement.cpp
    cplayerbattlefield.cpp
    cplayerbattlefieldlabel.cpp
    cplayerplacement.cpp
    cshipatcoords.cpp
    cshipvector.cpp
    main.cpp
    mainwindow.cpp

    battlefieldcoords.h
    cabstractbattlefield.h
    cabstractbattlefieldlabel.h
    cbattlefieldbutton.h
    cbattlefieldgrid.h
    cbattlefieldgriditerator.h
    cbattlefieldgridregister.h
    ccomputerbattlefield.h
    ccomputerbattlefieldlabel.h
    ccomputerplayer.h
    cgamemanagement.h
    cplayerbattlefield.h
    cplayerbattlefieldlabel.h
    cplayerplacement.h
    cshipatcoords.h
    cshipvector.h
    mainwindow.h
    randomizer.h

    mainwindow.ui

    res.qrc
)

qt_add_executable(Battleship
    ${BATTLESHIP_SOURCES}
)

target_include_directories(Battleship PRIVATE ${CMAKE_SOURCE_DIR}/Battleship/Battleship)
target_link_libraries(Battleship PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Battleship PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
qt_finalize_target(Battleship)

