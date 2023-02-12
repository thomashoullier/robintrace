cmake_minimum_required(VERSION 3.10)

project(robintrace)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(CMAKE_CXX_STANDARD 17)

# Robintrace modules
include(poaky/CMakeLists.txt)
include(pinyo/CMakeLists.txt)

# Robintrace library
add_library(robintrace INTERFACE)
target_link_libraries(robintrace INTERFACE poaky pinyo)
target_include_directories(robintrace INTERFACE .)

# Example program
add_executable(robintrace_example ./example.cpp)
target_link_libraries(robintrace_example PRIVATE robintrace)
set_target_properties(robintrace_example PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")

