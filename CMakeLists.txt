cmake_minimum_required(VERSION 3.10)

project(poaky)

## Compilation flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(main 
               ./src/base/Point3.cpp
               ./src/base/UVec3.cpp
               ./src/ray/ray.cpp
               ./src/shape/plane.cpp
               ./src/shape/sphere.cpp
               ./src/main.cpp )
target_include_directories(main PRIVATE ./src/ray/ ./src/base/ ./src/shape/)
