cmake_minimum_required(VERSION 3.5)

project(Monitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Widgets)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(Monitor
    MANUAL_FINALIZATION
    main.cpp
    UI/mainwindow.cpp
    UI/mainwindow.h
    UI/mainwindow.ui
    datareader.h datareader.cpp
    controller.h controller.cpp
)

qt_add_qml_module(Monitor
    URI qml
    VERSION 1.0
    QML_FILES
    content/App.qml
    content/CpuSpeedometer.qml
    content/DiskSpeedometer.qml
    content/MemSpeedometer.qml
    content/Speedometer.qml
)

target_link_libraries(Monitor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PRIVATE Qt6::Quick)

set_target_properties(Monitor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Monitor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Monitor)
endif()
