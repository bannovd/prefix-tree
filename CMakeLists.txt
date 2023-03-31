cmake_minimum_required(VERSION 3.5)

project(prefix-trie LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prefix-trie src/main.cpp src/trie.h)

install(TARGETS prefix-trie
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
