cmake_minimum_required(VERSION 3.10)

project(poaky)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

## Dependencies
Include(FetchContent)
FetchContent_Declare(
  Eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG master
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(EIGEN_BUILD_DOC OFF)
set(EIGEN_BUILD_PKGCONFIG OFF)
FetchContent_MakeAvailable(Eigen)

## Poaky library
file(GLOB_RECURSE POAKY_HEADERS ./src/*.h)
file(GLOB_RECURSE POAKY_SOURCES ./src/*.cpp)
add_library(poaky STATIC ${POAKY_SOURCES})
target_include_directories(poaky PUBLIC
                           "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>")
target_link_libraries(poaky PUBLIC Eigen3::Eigen)

option(build_main "Build poaky main" OFF)
if(build_main)
add_executable(main ./main.cpp)
target_link_libraries(main PRIVATE poaky)
set_target_properties(main PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

option(build_tests "Build poaky tests" OFF)
option(build_benchmark "Build poaky benchmarks" OFF)
option(build_coverage "Build poaky code coverage" OFF)

# Managing shared Catch2 dependency
if(build_tests OR build_benchmark OR build_coverage)
file(GLOB_RECURSE TEST_SRC ./test/*.cpp)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)
endif()

if(build_tests)
add_executable(test ./test/test_main.cpp ${TEST_SRC})
target_link_libraries(test PRIVATE poaky Catch2::Catch2WithMain)
endif()

if(build_benchmark)
## Benchmark
add_executable(benchmark ./benchmark/benchmark.cpp)
target_link_libraries(benchmark PRIVATE poaky Catch2::Catch2WithMain)
set_target_properties(benchmark PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

if(build_coverage)
include(CodeCoverage)
add_executable(coverage ${POAKY_SOURCES} ${TEST_SRC})
target_link_libraries(coverage PRIVATE poaky Catch2::Catch2WithMain)
set_target_properties(coverage PROPERTIES COMPILE_FLAGS
                  "${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
setup_target_for_coverage_gcovr_html(
  NAME coverage_report
  EXECUTABLE coverage
  BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
  EXCLUDE "test/*" "build/_deps/*")
endif()
