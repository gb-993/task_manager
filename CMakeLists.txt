cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.8.0/gcc_64")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled main.cpp
        goal.h
        goal.cpp
        category.cpp
        category.h
        categorymanager.cpp
        categorymanager.h
        mainwindow.cpp
        mainwindow.h
        controller.cpp
        controller.h
        addCategoryWindow.cpp
        addCategoryWindow.h
)
target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
