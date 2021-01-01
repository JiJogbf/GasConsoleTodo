cmake_minimum_required(VERSION 3.16)

project(GasConsoleTodo)

set(CXX_STANDARD 17)


aux_source_directory(src/cpp/main/gas CoreMainSrc)

add_executable(Todo
    src/cpp/main/main.cpp
    ${CoreMainSrc})