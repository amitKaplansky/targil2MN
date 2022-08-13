cmake_minimum_required(VERSION 3.20)
project(targil2MN)

set(CMAKE_CXX_STANDARD 20)

add_executable(targil2MN main.cpp max_heap.h max_heap.cpp min_heap.h min_heap.cpp min_max_heap.h min_max_heap.cpp double_min_max.cpp double_min_max.h general.h general.cpp pair.h)
