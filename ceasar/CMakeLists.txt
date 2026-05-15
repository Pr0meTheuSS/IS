cmake_minimum_required(VERSION 3.28)
project(ceasar_cipher)

set(CMAKE_CXX_STANDARD 23)

find_package(cxxopts REQUIRED)
find_package(fmt REQUIRED)
find_package(ftxui REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/**.cpp)

add_executable(ceasar ${SOURCES})

target_include_directories(ceasar PRIVATE src)

target_link_libraries(ceasar
    cxxopts::cxxopts
    fmt::fmt
    ftxui::screen
    ftxui::dom
    ftxui::component
)
