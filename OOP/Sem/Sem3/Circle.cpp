#include "Circle.h"
#include <math.h>
#include <iostream>


Circle::Circle(double rad){
    this->rad = rad;
}

double Circle::calculateArea(){
    return M_PI*(rad*rad)/2.0;
}

void Circle::printDescription(){
    std::cout << "Io sono un cerchio\n";
}