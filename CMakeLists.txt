cmake_minimum_required(VERSION 3.10)

project(MyProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the fmt library
find_package(fmt REQUIRED)

add_library(MyLibrary src/my_library.cpp)
target_include_directories(MyLibrary PRIVATE include)
target_link_libraries(MyLibrary PRIVATE fmt::fmt)

add_executable(MyExecutable src/main.cpp)
target_link_libraries(MyExecutable PRIVATE MyLibrary)