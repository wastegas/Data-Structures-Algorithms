cmake_minimum_required(VERSION 3.3.1)
project(Data-Structs)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_MACOSX_RPATH 1)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/Linked-Lists)

add_executable(testlink "src/Linked-Lists/main.cpp")
