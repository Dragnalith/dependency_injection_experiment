project(DiExperiment)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("include")

add_subdirectory(source/boost_di)
add_subdirectory(source/kangaru)
add_subdirectory(source/manual)