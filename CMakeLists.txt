cmake_minimum_required(VERSION 3.10)
project(CCollections C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CCollections
        Array.c
        Array.h
        testArray.c)
