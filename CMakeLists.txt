cmake_minimum_required(VERSION 3.7.2)
project(CCollections C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

#add_library(CCollections SHARED
#       src/ArrayList.c src/LinkedList.c src/PriorityQueue.c
#      include/ArrayList.h include/LinkedList.h include/PriorityQueue.h include/Stack.h include/TreeSet.h include/util.h)

add_executable(CCollectionsTest
        src/ArrayList.c
        include/ArrayList.h
        test/testArray.c src/LinkedList.c include/LinkedList.h include/Stack.h include/PriorityQueue.h include/util.h include/TreeSet.h src/PriorityQueue.c src/TreeSet.c)
