cmake_minimum_required(VERSION 3.10)

project(poaky)

## Compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(CMAKE_BUILD_TYPE "Release")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

## Main
file(GLOB_RECURSE SOURCES ./src/*.cpp)
add_library(Source INTERFACE)
target_include_directories(Source INTERFACE ./src)

add_executable(main ./main.cpp ${SOURCES})
target_link_libraries(main PRIVATE Source)


## Test
find_package(Catch2 REQUIRED)
find_package(CGAL)

file(GLOB_RECURSE TEST_SRC ./test/*.cpp)
add_library(Test_src INTERFACE)
target_include_directories(Test_src INTERFACE ./test)

add_executable(test ./test/test_main.cpp ${SOURCES} ${TEST_SRC})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain CGAL::CGAL
                                   Source Test_src)

## Benchmark
add_library(Benchmark INTERFACE)
target_include_directories(Benchmark INTERFACE ./benchmark)
add_library(CGAL_valid INTERFACE)
target_include_directories(CGAL_valid INTERFACE
                           ./test/cgal/)
add_executable(benchmark ./benchmark/benchmark.cpp ${SOURCES}
                         ./test/cgal/sphere_intersect_valid.cpp)
target_link_libraries(benchmark PRIVATE Catch2::Catch2WithMain CGAL::CGAL
                                        Source Benchmark CGAL_valid)

## Test coverage
include(CodeCoverage)
add_executable(coverage ${SOURCES} ${TEST_SRC})
target_link_libraries(coverage PRIVATE Catch2::Catch2WithMain CGAL::CGAL
                                       Source Test_src)
target_compile_options(coverage PRIVATE 
                       -O0 -Wall -fprofile-arcs -ftest-coverage)
setup_target_for_coverage_gcovr_html(
  NAME coverage_report
  EXECUTABLE coverage
  BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
  EXCLUDE "test/*")

