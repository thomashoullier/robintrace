cmake_minimum_required(VERSION 3.10)

project(poaky)

## Compilation flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES ./src/*.cpp)

add_library(Source INTERFACE)
target_include_directories(Source INTERFACE ./src)

add_executable(main ./main.cpp ${SOURCES})
target_link_libraries(main PRIVATE Source)

## Test
find_package(Catch2 REQUIRED)
find_package(CGAL)
set(CMAKE_BUILD_TYPE "Release")
add_executable(test ./test/test_main.cpp ${SOURCES}
                    ./test/sphere_intersect_valid.cpp)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain Source
                                   CGAL::CGAL)

## Benchmark
add_executable(benchmark ./benchmark/benchmark.cpp ${SOURCES})
target_link_libraries(benchmark PRIVATE Catch2::Catch2WithMain Source)
