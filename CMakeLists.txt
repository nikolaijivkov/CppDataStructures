cmake_minimum_required(VERSION 3.2)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(DataStructures ${SOURCE_FILES} list.h node.h stack.h queue.h tree.h)