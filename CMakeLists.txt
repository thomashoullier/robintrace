cmake_minimum_required(VERSION 3.10)

project(robintrace)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

# Robintrace modules
include(poaky/CMakeLists.txt)

# Example program
add_executable(robintrace_example ./example.cpp)
target_link_libraries(robintrace_example PRIVATE poaky)
set_target_properties(robintrace_example PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")

