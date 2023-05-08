# Pewit library
set(PEWIT_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE PEWIT_HEADERS "${PEWIT_DIR}/src/*.h")
file(GLOB_RECURSE PEWIT_SOURCES "${PEWIT_DIR}/src/*.cpp")
add_library(pewit STATIC ${PEWIT_SOURCES})
target_include_directories(pewit PUBLIC "$<BUILD_INTERFACE:${PEWIT_DIR}/src>")
target_link_libraries(pewit PUBLIC pinyo)
