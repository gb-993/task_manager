cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.8.1/gcc_64")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled main.cpp
        Model/goal.h
        Model/goal.cpp
        Model/category.cpp
        Model/category.h
        Model/categorymanager.cpp
        Model/categorymanager.h
        View/mainwindow.cpp
        View/mainwindow.h
        View/addCategoryDialog.cpp
        View/addCategoryDialog.h
        Controller/controller.cpp
        Controller/controller.h
        View/categoryWidget.cpp
        View/categoryWidget.h
        View/addTaskDialog.cpp
        View/addTaskDialog.h
        View/taskWidget.cpp
        View/taskWidget.h
        Model/subject.h
        View/observer.h
)
target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
