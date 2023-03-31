cmake_minimum_required(VERSION 3.5)

project(prefix-tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prefix-tree src/main.cpp)

install(TARGETS prefix-tree
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
