cmake_minimum_required(VERSION 3.5)

project(TextAdventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TEXTADVENTURE_SOURCES
    main.cpp

    console.h console.cpp
    ressources.h ressources.cpp
    randomizer.h randomizer.cpp

    cgamemanagement.h cgamemanagement.cpp
    cplayer.h cplayer.cpp

    cmap.h cmap.cpp
    cbattle.h cbattle.cpp

    rooms/roomfactory.h rooms/roomfactory.cpp
    rooms/croom.h  rooms/croom.cpp
    rooms/cstartingroom.h rooms/cstartingroom.cpp
    rooms/town/ctown.h rooms/town/ctown.cpp
    rooms/town/cshop.h rooms/town/cshop.cpp
    rooms/town/cchurch.h rooms/town/cchurch.cpp
    rooms/town/cblacksmith.h rooms/town/cblacksmith.cpp

    enemies/cenemy.h enemies/cenemy.cpp
    enemies/cmobenemy.h enemies/cmobenemy.cpp

    cinventory.h cinventory.cpp
    items/citem.h items/citem.cpp
    items/itemfactory.h items/itemfactory.cpp
    items/chealingpotion.h items/chealingpotion.cpp
    items/cjunkitem.h items/cjunkitem.cpp
    items/cenhancableitem.h items/cenhancableitem.cpp
    items/csword.h items/csword.cpp
    items/cshield.h items/cshield.cpp
    items/cphoenixfeather.h items/cphoenixfeather.cpp
)

add_executable(TextAdventure ${TEXTADVENTURE_SOURCES})

target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/items)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/enemies)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/rooms)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/rooms/town)

include(GNUInstallDirs)
install(TARGETS TextAdventure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

