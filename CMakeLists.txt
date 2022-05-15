cmake_minimum_required(VERSION 3.15)
project(Skeleton)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_compile_definitions(MEMTRACE)

add_executable(Skeleton main.cpp film.h filmtar.h gtest_lite.h memtrace.h memtrace.cpp string5.h string5.cpp filmtar.cpp film.cpp menu.hpp)
