set(TICTACTOE2_SOURCES
	CMakeLists.txt

    computerenemy.cpp
	main.cpp
	mainwindow.cpp
	playermanagement.cpp
	playfield.cpp
	playfieldcoords.cpp

    computerenemy.h
	mainwindow.h
	playermanagement.h
	playfield.h
	playfieldcoords.h
    mainwindow.ui
)

add_executable(TicTacToe2
    ${TICTACTOE2_SOURCES}
)

target_link_libraries(TicTacToe2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(TicTacToe2 PRIVATE ${CMAKE_SOURCE_DIR}/TicTacToe2/TicTacToe2)

set_target_properties(TicTacToe2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TicTacToe2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
