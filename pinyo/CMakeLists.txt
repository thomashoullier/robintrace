## Dependencies
#include("${CMAKE_CURRENT_LIST_DIR}/../poaky/CMakeLists.txt")

## Pinyo library
set(PINYO_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE PINYO_HEADERS "${PINYO_DIR}/src/*.h")
file(GLOB_RECURSE PINYO_SOURCES "${PINYO_DIR}/src/*.cpp")
add_library(pinyo STATIC ${PINYO_SOURCES})
target_include_directories(pinyo PUBLIC
                           "$<BUILD_INTERFACE:${PINYO_DIR}/src>")
target_link_libraries(pinyo PUBLIC poaky)

option(pinyo_build_tests "Build pinyo tests" OFF)
option(pinyo_build_benchmark "Build pinyo benchmarks" OFF)
option(pinyo_build_coverage "Build pinyo code coverage" OFF)

# Managing shared Catch2 dependency
if(pinyo_build_tests OR pinyo_build_benchmark OR pinyo_build_coverage)
file(GLOB_RECURSE TEST_SRC ./test/*.cpp)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)
endif()

if(pinyo_build_tests)
add_executable(pinyo_test ./test/test_main.cpp ${TEST_SRC})
target_link_libraries(pinyo_test PRIVATE pinyo Catch2::Catch2WithMain)
endif()

if(pinyo_build_benchmark)
add_executable(pinyo_benchmark ./benchmark/benchmark.cpp)
target_link_libraries(pinyo_benchmark PRIVATE pinyo Catch2::Catch2WithMain)
set_target_properties(pinyo_benchmark PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

if(pinyo_build_coverage)
include(CodeCoverage)
add_executable(pinyo_coverage ${PINYO_SOURCES} ${TEST_SRC})
target_link_libraries(pinyo_coverage PRIVATE pinyo Catch2::Catch2WithMain)
set_target_properties(pinyo_coverage PROPERTIES COMPILE_FLAGS
                  "${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
setup_target_for_coverage_gcovr_html(
  NAME pinyo_coverage_report
  EXECUTABLE pinyo_coverage
  BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
  EXCLUDE "test/*" "build/_deps/*")
endif()
