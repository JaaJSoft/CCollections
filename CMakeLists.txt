cmake_minimum_required(VERSION 3.9)
project(Array C)

set(CMAKE_C_STANDARD 11)

add_executable(Array Array.c Array.h testArray.c)