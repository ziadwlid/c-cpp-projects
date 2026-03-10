cmake_minimum_required(VERSION 3.10)

project(calc_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(calc
        src/main.cpp
        src/calculator.cpp
)

target_include_directories(calc PRIVATE include)