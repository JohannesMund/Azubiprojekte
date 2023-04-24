set(MEMORY_SOURCES
    CMakeLists.txt
    cdisplaylabel.cpp
    cmemorybutton.cpp
    cplayfield.cpp
    cresourcehelper.cpp
    gamemanagement.cpp
    main.cpp
    mainwindow.cpp
    utils.cpp

    cdisplaylabel.h
    cmemorybutton.h
    cplayfield.h
    cresourcehelper.h
    gamemanagement.h
    mainwindow.h
    utils.h

    mainwindow.ui

    memory.qrc
)

add_executable(Memory
    ${MEMORY_SOURCES}
)

target_link_libraries(Memory PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(Memory PRIVATE ${CMAKE_SOURCE_DIR}/Memory)

set_target_properties(Memory PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Memory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
