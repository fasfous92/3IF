cmake_minimum_required(VERSION 3.23)
project(c__)

set(CMAKE_CXX_STANDARD 14)

include_directories(TP1)

add_executable(c__
        TP1/main.cpp
        TP1/Ensemble.cpp

        )
