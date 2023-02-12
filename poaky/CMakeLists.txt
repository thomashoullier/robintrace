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
set(POAKY_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE POAKY_HEADERS "${POAKY_DIR}/src/*.h")
file(GLOB_RECURSE POAKY_SOURCES "${POAKY_DIR}/src/*.cpp")
add_library(poaky STATIC ${POAKY_SOURCES})
target_include_directories(poaky PUBLIC
                           "$<BUILD_INTERFACE:${POAKY_DIR}/src>")
target_link_libraries(poaky PUBLIC Eigen3::Eigen)

option(poaky_build_tests "Build poaky tests" OFF)
option(poaky_build_benchmark "Build poaky benchmarks" OFF)
option(poaky_build_coverage "Build poaky code coverage" OFF)

# Managing shared Catch2 dependency
if(poaky_build_tests OR poaky_build_benchmark OR poaky_build_coverage)
file(GLOB_RECURSE TEST_SRC "${POAKY_DIR}/test/*.cpp")
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)
endif()

if(poaky_build_tests)
add_executable(poaky_test "${POAKY_DIR}/test/test_main.cpp" ${TEST_SRC})
target_link_libraries(poaky_test PRIVATE poaky Catch2::Catch2WithMain)
endif()

if(poaky_build_benchmark)
## Benchmark
file(GLOB_RECURSE BENCH_SRC "${POAKY_DIR}/benchmark/*.cpp")
add_executable(poaky_benchmark "${POAKY_DIR}/benchmark/benchmark.cpp"
                               ${BENCH_SRC})
target_link_libraries(poaky_benchmark PRIVATE poaky Catch2::Catch2WithMain)
set_target_properties(poaky_benchmark PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

if(poaky_build_coverage)
include(CodeCoverage)
add_executable(poaky_coverage ${POAKY_SOURCES} ${TEST_SRC})
target_link_libraries(poaky_coverage PRIVATE poaky Catch2::Catch2WithMain)
set_target_properties(poaky_coverage PROPERTIES COMPILE_FLAGS
                  "${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
setup_target_for_coverage_lcov(
  NAME poaky_coverage_report
  EXECUTABLE poaky_coverage
  BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
  EXCLUDE "${POAKY_DIR}/test/*" "build/_deps/*" "/usr/*")
endif()
