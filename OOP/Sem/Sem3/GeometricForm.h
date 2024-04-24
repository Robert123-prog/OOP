#pragma once
#include <iostream>

template <typename T> T calculateArea(){

}


class GeometricForm{
public:
    virtual double calculateArea(){return 0.0;};
    virtual void printDescription(){std::cout << "GeometricForm";};
};