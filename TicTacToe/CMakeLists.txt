set(TICTACTOE_SOURCES
    CMakeLists.txt

    main.cpp
	mainwindow.cpp
	playermanagement.cpp
	playfield.cpp

    mainwindow.h
	playermanagement.h
	playfield.h
    
	mainwindow.ui
)

add_executable(TicTacToe
    ${TICTACTOE_SOURCES}
)

target_link_libraries(TicTacToe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(TicTacToe PRIVATE ${CMAKE_SOURCE_DIR}/TicTacToe)

set_target_properties(TicTacToe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TicTacToe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
