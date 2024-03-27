cmake_minimum_required(VERSION 3.27)
project(Laborator2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laborator2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h
        SortedIndexedList.cpp
        SortedIndexedList.h)
