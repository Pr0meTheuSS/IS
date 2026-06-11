cmake_minimum_required(VERSION 3.15)
project(vernam_cipher)

set(CMAKE_CXX_STANDARD 17)

add_executable(vernam
    src/main.cpp
    src/vernam.cpp
    src/rc4.cpp
    src/rng.cpp
)
