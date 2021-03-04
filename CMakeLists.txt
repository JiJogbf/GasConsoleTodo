cmake_minimum_required(VERSION 3.16)

project(GasConsoleTodo)

set(CXX_STANDARD 17)
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic ) # -Werror
endif()

aux_source_directory(src/cpp/main/gas CoreMainSrc)
aux_source_directory(src/cpp/main/gas/states CoreMainSrc)

add_executable(Todo
    src/cpp/main/main.cpp
    ${CoreMainSrc})