cmake_minimum_required(VERSION 3.5)

project(TextAdventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TEXTADVENTURE_SOURCES
    main.cpp

    console.h console.cpp
    colorconsole.h colorconsole.cpp
    cmenu.h cmenu.cpp

    ressources.h ressources.cpp
    randomizer.h randomizer.cpp

    cgamemanagement.h cgamemanagement.cpp
    cplayer.h cplayer.cpp
    cmap.h cmap.cpp
    cbattle.h cbattle.cpp

    companion/companionfactory.h companion/companionfactory.cpp
    companion/ccompanion.h companion/ccompanion.cpp
    companion/cattackercompanion.h companion/cattackercompanion.cpp
    companion/cdefendercompanion.h companion/cdefendercompanion.cpp
    companion/chealercompanion.h companion/chealercompanion.cpp
    companion/cscarymonstercompanion.h companion/cscarymonstercompanion.cpp


    rooms/roomfactory.h rooms/roomfactory.cpp
    rooms/croom.h  rooms/croom.cpp
    rooms/cstartingroom.h rooms/cstartingroom.cpp
    rooms/cinjuredpet.h rooms/cinjuredpet.cpp

    rooms/town/ctown.h rooms/town/ctown.cpp
    rooms/town/ctownmodule.h rooms/town/ctownmodule.cpp
    rooms/town/cshop.h rooms/town/cshop.cpp
    rooms/town/cchurch.h rooms/town/cchurch.cpp
    rooms/town/cblacksmith.h rooms/town/cblacksmith.cpp
    rooms/town/cfarm.h rooms/town/cfarm.cpp
    rooms/town/ctavern.h rooms/town/ctavern.cpp

    enemies/cenemy.h enemies/cenemy.cpp
    enemies/cmobenemy.h enemies/cmobenemy.cpp
    enemies/cbountyenemy.h enemies/cbountyenemy.cpp
    enemies/clivingchest.h enemies/clivingchest.cpp

    tasks/ctask.h tasks/ctask.cpp
    tasks/cbountyhunt.h tasks/cbountyhunt.cpp

    cinventory.h cinventory.cpp
    items/equipment/cequipment.h items/equipment/cequipment.cpp
    items/equipment/csword.h items/equipment/csword.cpp
    items/equipment/cshield.h items/equipment/cshield.cpp
    items/equipment/carmor.h items/equipment/carmor.cpp
    items/equipment/cjunkshield.h items/equipment/cjunkshield.cpp
    items/equipment/cjunksword.h items/equipment/cjunksword.cpp
    items/equipment/cjunkarmor.h items/equipment/cjunkarmor.cpp

    items/citem.h items/citem.cpp
    items/itemfactory.h items/itemfactory.cpp
    items/chealingpotion.h items/chealingpotion.cpp
    items/cjunkitem.h items/cjunkitem.cpp
    items/cphoenixfeather.h items/cphoenixfeather.cpp
    items/cheartcontainer.h items/cheartcontainer.cpp
    items/curzasglasses.h items/curzasglasses.cpp
    items/cbomb.h items/cbomb.cpp

    encounters/encounterregister.h
    encounters/cencounter.h encounters/cencounter.cpp
    encounters/cbattleencounter.h encounters/cbattleencounter.cpp
    encounters/cdeadhero.h encounters/cdeadhero.cpp
    encounters/cmysteriouschest.h encounters/cmysteriouschest.cpp
)

add_executable(TextAdventure ${TEXTADVENTURE_SOURCES})


target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/companion)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/items)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/items/equipment)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/enemies)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/rooms)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/rooms/town)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/tasks)
target_include_directories(TextAdventure PRIVATE ${CMAKE_SOURCE_DIR}/encounters)


include(GNUInstallDirs)
install(TARGETS TextAdventure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

