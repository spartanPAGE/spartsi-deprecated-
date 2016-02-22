cmake_minimum_required(VERSION 3.4)
project(spartsi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(dep)
include_directories(src)

set(SOURCE_FILES test/main.cpp test/node/node-test.cpp)
add_executable(spartsi ${SOURCE_FILES})

