cmake_minimum_required(VERSION 3.27)
project(GeCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeCalc main.cpp)

set(CMAKE_EXE_LINKER_FLAGS -static)