cmake_minimum_required(VERSION 3.23)
project(c__)

set(CMAKE_CXX_STANDARD 14)

include_directories(TestTp1)

add_executable(c__
        TestTp1/main.cpp
        TestTp1/Ensemble.cpp
        )
