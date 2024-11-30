cmake_minimum_required(VERSION 3.29)
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(vendor/SDL)

add_executable(tinyrenderer main.cpp
        app/app.cpp
        app/app.h
        App/App.cpp
        App/App.h)

target_include_directories(tinyrenderer PRIVATE vendor/SDL/include)
target_link_libraries(tinyrenderer PRIVATE SDL3::SDL3)
