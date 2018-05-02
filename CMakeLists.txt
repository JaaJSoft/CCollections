cmake_minimum_required(VERSION 3.7.2)
project(CCollections C)

enable_testing()

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(CCollections SHARED
        src/ArrayList.c
        src/LinkedList.c
        src/PriorityQueue.c
        src/TreeSet.c
        include/ArrayList.h
        include/LinkedList.h
        include/PriorityQueue.h
        include/Stack.h
        include/TreeSet.h
        include/util.h
        )

add_executable(TestArrayList
        src/ArrayList.c
        test/testArray.c
        include/ArrayList.h
        include/util.h
        )

add_executable(TestTreeSet
        src/TreeSet.c
        test/testTreeSet.c
        include/TreeSet.h
        include/util.h
        )

add_executable(TestLinkedList
        src/LinkedList.c
        test/testLinkedList.c
        include/LinkedList.h
        include/util.h
        )

add_executable(TestPriorityQueue
        src/PriorityQueue.c
        include/PriorityQueue.h
        include/util.h
        test/testPriorityQueue.c
        )

add_executable(TestStack
        src/Stack.c
        include/Stack.h
        include/util.h
        test/testStack.c
        )





