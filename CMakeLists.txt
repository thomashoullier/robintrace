cmake_minimum_required(VERSION 3.10)

project(robintrace)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(CMAKE_CXX_STANDARD 17)

set(ROBINTRACE_DIR "${CMAKE_CURRENT_LIST_DIR}")

# Robintrace modules
include(src/poaky/CMakeLists.txt)
include(src/pinyo/CMakeLists.txt)
include(src/pewit/CMakeLists.txt)

# Robintrace library
add_library(robintrace INTERFACE)
target_link_libraries(robintrace INTERFACE poaky pinyo pewit)
target_include_directories(robintrace INTERFACE ./include/)

# Example program
option(robintrace_build_example "Build robintrace example" OFF)
if(robintrace_build_example)
add_executable(robintrace_example ./example.cpp)
target_link_libraries(robintrace_example PRIVATE robintrace)
set_target_properties(robintrace_example PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

option(robintrace_build_tests "Build robintrace tests" OFF)
option(robintrace_build_coverage "Build robintrace test code coverage" OFF)
option(robintrace_build_benchmark "Build robintrace benchmarks" OFF)

# Shared Catch2 dependency
if(robintrace_build_tests OR robintrace_build_coverage
   OR robintrace_build_benchmark)
file(GLOB_RECURSE ROBINTRACE_TEST_SRC "${ROBINTRACE_DIR}/test/*.cpp")
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)
endif()

# Tests
if(robintrace_build_tests)
add_executable(robintrace_test "${ROBINTRACE_DIR}/test/test_main.cpp"
                               ${ROBINTRACE_TEST_SRC})
target_link_libraries(robintrace_test PRIVATE robintrace Catch2::Catch2WithMain)
endif()

# Test code coverage
if(robintrace_build_coverage)
include(CodeCoverage)
file(GLOB_RECURSE ROBINTRACE_SRC "${ROBINTRACE_DIR}/src/*.cpp")
add_executable(robintrace_coverage ${ROBINTRACE_SRC} ${ROBINTRACE_TEST_SRC})
target_link_libraries(robintrace_coverage PRIVATE robintrace
                                                  Catch2::Catch2WithMain)
set_target_properties(robintrace_coverage PROPERTIES COMPILE_FLAGS
                  "${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
setup_target_for_coverage_lcov(
  NAME robintrace_coverage_report
  EXECUTABLE robintrace_coverage
  BASE_DIRECTORY "${ROBINTRACE_DIR}"
  EXCLUDE "${ROBINTRACE_DIR}/test/*" "build/_deps/*" "/usr/*")
endif()

# Benchmark
if(robintrace_build_benchmark)
file(GLOB_RECURSE ROBINTRACE_BENCH_SRC "${ROBINTRACE_DIR}/benchmark/*.cpp")
add_executable(robintrace_benchmark
               "${ROBINTRACE_DIR}/benchmark/robintrace_benchmark.cpp"
               ${ROBINTRACE_BENCH_SRC})
target_link_libraries(robintrace_benchmark PRIVATE robintrace
                                                   Catch2::Catch2WithMain)
set_target_properties(robintrace_benchmark PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()
