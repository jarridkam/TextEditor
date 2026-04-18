cmake_minimum_required(VERSION 3.16)
project(TextEditor C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(raylib)

add_executable(TextEditor main.c
        editor_inputs.c
        editor_inputs.h
        main.c
)

target_link_libraries(TextEditor PRIVATE raylib)