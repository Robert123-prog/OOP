#pragma once
#include "GeometricForm.h"

class Square: public GeometricForm{
private:
    double lat;
    /* data */
public:
    double calculateArea();
    void printDescription();
    Square(double lat);
};

