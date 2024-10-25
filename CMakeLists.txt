cmake_minimum_required(VERSION 3.16)
project(AlMaani LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Sql package
find_package(Qt6 REQUIRED COMPONENTS Sql)

add_executable(AlMaani
            main.cpp
            mainwindow.h mainwindow.cpp mainwindow.ui
)

target_link_libraries(AlMaani PRIVATE Qt6::Widgets)

target_link_libraries(AlMaani PRIVATE Qt6::Sql)

