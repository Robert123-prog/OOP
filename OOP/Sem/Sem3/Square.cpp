#include "Square.h"
#include <iostream>

Square::Square(double lat){
    this->lat = lat;
}

double Square::calculateArea(){
    return this->lat*this->lat;
}

void Square::printDescription(){
    std::cout << "Io sono un quadrato\n";
}