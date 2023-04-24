
set(TICTACKTOE2TEST_SOURCES
    ../TicTacToe2/playfieldcoords.cpp
    ../TicTacToe2/playfield.cpp
    ../TicTacToe2/computerenemy.cpp

    ../TicTacToe2/playfieldcoords.h
    ../TicTacToe2/playfield.h
    ../TicTacToe2/computerenemy.h


    computerenemy_test.cpp
    main.cpp
    playfieldcoords_test.cpp
    playfield_test.cpp

    computerenemy_test.h
    playfieldcoords_test.h
    playfield_test.h
    testdefines.h
)

qt_add_executable(TicTacToe2Test
    MANUAL_FINALIZATION
    ${TICTACKTOE2TEST_SOURCES}
)

target_include_directories(TicTacToe2Test PRIVATE ../TicTacToe2/)

target_link_libraries(TicTacToe2Test PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(TicTacToe2Test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(TicTacToe2Test PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TicTacToe2Test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    qt_finalize_executable(TicTacToe2Test)

