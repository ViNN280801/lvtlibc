cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(lvt_c
    DESCRIPTION "This library will help you on a initial steps"
    VERSION 1.0
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra")

add_library(${PROJECT_NAME} SHARED lvtlib.c)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)
