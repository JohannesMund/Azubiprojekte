cmake_minimum_required(VERSION 3.5)

project(TextAdventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TEXTADVENTURE_SOURCES
    main.cpp

    conio.h conio.cpp
    ressources.h ressources.cpp

    cgamemanagement.h cgamemanagement.cpp
    cplayer.h cplayer.cpp
    randomizer.h randomizer.cpp

    cmap.h cmap.cpp
    roomfactory.h roomfactory.cpp
    croom.h  croom.cpp

    cinventory.h cinventory.cpp
    citem.h citem.cpp

    items/itemfactory.h items/itemfactory.cpp
    items/chealingpotion.h items/chealingpotion.cpp
    items/crubbishitem.h items/crubbishitem.cpp
)

add_executable(TextAdventure ${TEXTADVENTURE_SOURCES})

target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/Items)

include(GNUInstallDirs)
install(TARGETS TextAdventure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

