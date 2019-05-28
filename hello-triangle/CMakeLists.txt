cmake_minimum_required(VERSION 3.5)

project(hello-triangle)
set(PROJECT_VERSION 00.00.00)

add_subdirectory(src)

add_library(
    main.cpp
)

add_executable(hello-triangle main.cpp)