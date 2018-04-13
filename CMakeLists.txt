cmake_minimum_required(VERSION 3.7.2)
project(CCollections C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CCollections
        src/ArrayList.c
        include/ArrayList.h
        test/testArray.c src/LinkedList.c include/LinkedList.h include/util.h)
