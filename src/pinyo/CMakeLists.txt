# Pinyo library
set(PINYO_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE PINYO_HEADERS "${PINYO_DIR}/src/*.h")
file(GLOB_RECURSE PINYO_SOURCES "${PINYO_DIR}/src/*.cpp")
add_library(pinyo STATIC ${PINYO_SOURCES})
target_include_directories(pinyo PUBLIC
                           "$<BUILD_INTERFACE:${PINYO_DIR}/src>")
target_link_libraries(pinyo PUBLIC poaky)
