cmake_minimum_required(VERSION 3.15)
project(entropy_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(entropy
    src/main.cpp
    src/entropy.cpp
)
