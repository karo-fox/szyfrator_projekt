cmake_minimum_required(VERSION 3.10)
project(Szyfrator VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${PROJECT_SOURCE_DIR}/szyfrator_c++")
find_package(fmt REQUIRED)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/szyfrator_c++/*.cpp" "${PROJECT_SOURCE_DIR}/szyfrator_c++/*.h")

add_executable(Szyfrator "${SOURCES}")
target_link_libraries(Szyfrator fmt::fmt)