cmake_minimum_required(VERSION 3.27)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp
        Rational.cpp
        Rational.h
        Rational_test.cpp
        Complex.cpp
        Complex.h
        Complex_test.cpp
)
