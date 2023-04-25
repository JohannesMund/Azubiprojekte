cmake_minimum_required(VERSION 3.5)

project(Azubiprojekte VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Test)
qt_standard_project_setup()

add_subdirectory("Battleship")
target_include_directories(Battleship PUBLIC)

add_subdirectory("ConnectFour")
target_include_directories(ConnectFour PUBLIC)

add_subdirectory("Memory")
target_include_directories(Memory PUBLIC)

add_subdirectory("Minesweeper")
target_include_directories(Minesweeper PUBLIC)

add_subdirectory("Rechner")
target_include_directories(Rechner PUBLIC)

add_subdirectory("TicTacToe")
target_include_directories(TicTacToe PUBLIC)

add_subdirectory("TicTacToe2")
target_include_directories(TicTacToe2 PUBLIC)

install(TARGETS Battleship ConnectFour Memory Minesweeper Rechner TicTacToe TicTacToe2 RechnerTest TicTacToe2Test
        CONFIGURATIONS Debug
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(TARGETS Battleship ConnectFour Memory Minesweeper Rechner TicTacToe TicTacToe2
        CONFIGURATIONS Release
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}/Release)

qt_generate_deploy_app_script(
    TARGET Battleship
    NO_TRANSLATIONS # wichtig wenn wir keine übersetzungen haben, sonst gibt es einen fehler.
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})


