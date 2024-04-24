cmake_minimum_required(VERSION 3.27)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4 main.cpp
        Controller/Controller.cpp
        Controller/Controller.h
        UI/UI.cpp
        UI/UI.h
        Repository/Repository.cpp
        Repository/Repository.h
        Product/Product.cpp
        Product/Product.h)
