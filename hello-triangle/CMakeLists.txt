cmake_minimum_required(VERSION 3.5)

project(hello-triangle)
set(PROJECT_VERSION 00.00.00)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set(DEPENDENCIES "${CMAKE_CURRENT_LIST_DIR}/../dependencies")

set(INCLUDE_DIRS "${DEPENDENCIES}/include")

set(LIB "${DEPENDENCIES}/lib")
set(LIBRARIES "${LIB}/SDL2.lib;${LIB}/SDL2main.lib")

include_directories(${INCLUDE_DIRS})
link_libraries(${LIBRARIES})

file(GLOB SOURCES "src/*.cpp")
add_executable(hello-triangle ${SOURCES})