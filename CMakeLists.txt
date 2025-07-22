cmake_minimum_required(VERSION 3.31)
project(bonsai)

set(CMAKE_CXX_STANDARD 20)

add_executable(bonsai main.cpp
        bonsai/bonsai.hpp)
