

set(BATTLESHIPTEST_SOURCES
    ../Battleship/cbattlefieldgrid.cpp
    ../Battleship/cshipvector.cpp
    ../Battleship/cshipatcoords.cpp
    ../Battleship/battlefieldcoords.cpp

    battlefieldgrid_test.h
    shipvector_test.h

    main.cpp
    battlefieldgrid_test.cpp
    shipvector_test.cpp

)

qt_add_executable(BattleshipTest
    ${BATTLESHIPTEST_SOURCES}
)

target_include_directories(BattleshipTest PRIVATE ${CMAKE_SOURCE_DIR}/Battleship/Battleship)
target_include_directories(BattleshipTest PRIVATE ${CMAKE_SOURCE_DIR}/Battleship/BattleshipTest)

target_link_libraries(BattleshipTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(BattleshipTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(BattleshipTest PRIVATE UNIT_TESTING)
target_compile_definitions(BattleshipTest PRIVATE -DNDEBUG)

set_target_properties(BattleshipTest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_target(BattleshipTest)
