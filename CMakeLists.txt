cmake_minimum_required(VERSION 3.10)

project(poaky)

## Compilation flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES
     ./src/base/*.cpp
     ./src/ray/*.cpp
     ./src/shape/*.cpp)

add_library(Source INTERFACE)
target_include_directories(Source INTERFACE ./src)

#add_executable(main 
#               ./src/base/Point3.cpp
#               ./src/base/UVec3.cpp
#               ./src/ray/ray.cpp
#               ./src/shape/plane.cpp
#               ./src/shape/sphere.cpp
#               ./src/main.cpp )

add_executable(main ./src/main.cpp ${SOURCES})
target_link_libraries(main PRIVATE Source)

## Test
find_package(Catch2 REQUIRED)
add_executable(test ./test/test_main.cpp ${SOURCES})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain Source)
