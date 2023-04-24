set(MINESWEEPER_SOURCES
    CMakeLists.txt
    cdisplay.cpp
    cminesweeperbutton.cpp
    cplayfield.cpp
    main.cpp
    mainwindow.cpp

    cdisplay.h
    cminesweeperbutton.h
    cplayfield.h
    mainwindow.h

    mainwindow.ui

    res.qrc
)

add_executable(Minesweeper
    ${MINESWEEPER_SOURCES}
)

target_link_libraries(Minesweeper PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(Minesweeper PRIVATE ${CMAKE_SOURCE_DIR}/Minesweeper)

set_target_properties(Minesweeper PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Minesweeper
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
