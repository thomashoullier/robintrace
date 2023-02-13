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

