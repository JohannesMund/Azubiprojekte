set(RECHNERTEST_SOURCES
    ../Rechner/calculatornumber.cpp
    ../Rechner/result.cpp

    calculatornumber_test.cpp
    main.cpp
    result_test.cpp

    calculatornumber_test.h
    result_test.h
)

qt_add_executable(RechnerTest
    ${RECHNERTEST_SOURCES}
)

target_link_libraries(RechnerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

target_include_directories(RechnerTest PRIVATE ${CMAKE_SOURCE_DIR}/Rechner/Rechner)
target_include_directories(RechnerTest PRIVATE ${CMAKE_SOURCE_DIR}/Rechner/RechnerTest)



set_target_properties(RechnerTest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_target(RechnerTest)
