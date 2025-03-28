cmake_minimum_required(VERSION 3.30)
project(DataStructureClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructureClass others/main.cpp
        others/Merge.cpp
        LinearList/SequentialLists.h
        LinearList/main.cpp
        LinearList/TwoPoly.h
        LinearList/LinkedChain.h
        test.cpp
)
