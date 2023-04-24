set(RECHNER_SOURCES
    calculator.cpp
    calculatornumber.cpp
    main.cpp
    mainwindow.cpp
    result.cpp

    calculator.h
    calculatornumber.h
    mainwindow.h
    result.h
    mainwindow.ui
)

qt_add_executable(Rechner
    MANUAL_FINALIZATION
    ${RECHNER_SOURCES}
)

target_link_libraries(Rechner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Rechner PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Rechner
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    qt_finalize_executable(Rechner)

