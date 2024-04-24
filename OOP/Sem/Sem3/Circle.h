#pragma once
#include "GeometricForm.h"

class Circle : public GeometricForm{
public:
    double rad;
    Circle(double radius);

    double calculateArea();
    void printDescription();
};