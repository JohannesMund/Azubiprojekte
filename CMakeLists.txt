cmake_minimum_required(VERSION 3.5)

project(Azubiprojekte_cmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

add_subdirectory("BattleShip")
target_include_directories(Battleship PUBLIC BattleShip/)

add_subdirectory("ConnectFour")
target_include_directories(ConnectFour PUBLIC ConnectFour/)

add_subdirectory("Memory")
target_include_directories(Memory PUBLIC Memory/)

add_subdirectory("Minesweeper")
target_include_directories(Minesweeper PUBLIC Minesweeper/)

add_subdirectory("Rechner")
target_include_directories(Rechner PUBLIC Rechner/)

add_subdirectory("TicTacToe")
target_include_directories(TicTacToe PUBLIC TicTacToe/)

add_subdirectory("TicTacToe2")
target_include_directories(TicTacToe2 PUBLIC TicTacToe2/)
