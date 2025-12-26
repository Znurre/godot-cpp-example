cmake_minimum_required(VERSION 3.24)

include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/aminya/project_options/archive/refs/tags/v0.41.0.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

run_vcpkg(
    VCPKG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg
)

project(my_gd_extension LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    my_gd_extension.gdextension
    extension.cpp
    node.hpp
    node.cpp
)

find_package(unofficial-godot-cpp CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    unofficial::godot::cpp
)
