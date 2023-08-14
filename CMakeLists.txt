cmake_minimum_required(VERSION 3.26)
project(src/loq2)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        src/loq2/native/state/place.cpp
        src/loq2/native/state/util.cpp)
