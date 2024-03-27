//
// Created by user on 18-Mar-24.
//

#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

#include <string>


class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double re, double im);

    double getReal();

    double getImaginary();

    Complex add(const Complex &other) const;

    Complex operator+(const Complex other) const;

    Complex operator-(const Complex other) const;

    Complex operator*(const Complex other) const;

    Complex operator/(const Complex other) const;

    Complex subtract(const Complex &other) const;

    Complex multiply(const Complex &other) const;

    Complex divide(const Complex &other) const;

    double absolute();

    double computePolar();

    std::string text();


};


#endif //LAB2_COMPLEX_H

