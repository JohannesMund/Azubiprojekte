set(CONNECTFOUR_SOURCES
    CMakeLists.txt
    cbuttonbox.cpp
    cfield.cpp
    cplayermanagement.cpp
    cplayfield.cpp
    main.cpp
    mainwindow.cpp

    cbuttonbox.h
    cfield.h
    cplayermanagement.h
    cplayfield.h
    mainwindow.h
    mainwindow.ui

    connectFour.qrc
)

qt_add_executable(ConnectFour
    MANUAL_FINALIZATION
    ${CONNECTFOUR_SOURCES}
)

target_link_libraries(ConnectFour PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(ConnectFour PUBLIC ConnectFour/)
set_target_properties(ConnectFour PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ConnectFour
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    qt_finalize_executable(ConnectFour)

