cmake_minimum_required(VERSION 3.17)
project(treasure-hunter)

set(CMAKE_CXX_STANDARD 14)

add_executable(treasure-hunter main.cpp GameObject.cpp GameObject.h Position.cpp Position.h)