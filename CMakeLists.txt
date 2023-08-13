cmake_minimum_required(VERSION 3.26)
project(loq2)

set(CMAKE_CXX_STANDARD 20)

add_executable(loq2 library.h point/point.cpp point/point.h
        util.h
        map/map.cpp
        map/map.h
        block/block.h
        block/lblock.cpp
        block/iblock.cpp
        state/state.h
        state/util.cpp
        state/cross.cpp
        state/endable.cpp
        state/move.cpp
        state/place.cpp)
