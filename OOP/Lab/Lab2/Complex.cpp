//
// Created by user on 18-Mar-24.
//

#include "Complex.h"
#include <cmath>
#include <string>

using namespace std;


Complex::Complex(double re, double im) {
    this->real = re;
    this->imaginary = im;
}

double Complex::getReal() {
    return this->real;
}

double Complex::getImaginary() {
    return this->imaginary;
}

Complex Complex::add(const Complex &other) const {
    return {this->real + other.real, this->imaginary + other.imaginary};
}

Complex Complex::operator+(const Complex other) const {
    return {this->real + other.real, this->imaginary + other.imaginary};
}

Complex Complex::subtract(const Complex &other) const {
    return {this->real - other.real, this->imaginary - other.imaginary};
}

Complex Complex::operator-(const Complex other) const {
    return {this->real - other.real, this->imaginary - other.imaginary};
}

Complex Complex::multiply(const Complex &other) const {
    return {this->real * other.real - this->imaginary * other.imaginary,
            this->real * other.imaginary + this->imaginary * other.real};
}

Complex Complex::operator*(const Complex other) const {
    return {this->real * other.real - this->imaginary * other.imaginary,
            this->real * other.imaginary + this->imaginary * other.real};
}

Complex Complex::divide(const Complex &other) const {
    return {(this->real * other.real + this->imaginary * other.imaginary) / other.real * other.real +
            other.imaginary * other.imaginary,
            (this->imaginary * other.real - this->real * other.imaginary) / other.imaginary * other.imaginary};
}

Complex Complex::operator/(const Complex other) const {
    return {(this->real * other.real + this->imaginary * other.imaginary) / other.real * other.real +
            other.imaginary * other.imaginary,
            (this->imaginary * other.real - this->real * other.imaginary) / other.imaginary * other.imaginary};
}

double Complex::absolute() {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

double Complex::computePolar() {
    if (this->real > 0) {
        float theta = atan(this->imaginary / this->real);
        return absolute() * (cos(theta) + sqrt(-1) * (sin(theta)));
    } else {
        float theta = atan(this->imaginary / this->real) + 3.14;
        return absolute() * (cos(theta) + sqrt(-1) * sin(theta));
    }
}

string Complex::text() {

    return to_string(this->real) + " + " + to_string(this->imaginary) + "i";

}