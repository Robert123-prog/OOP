//
// Created by user on 17-Mar-24.
//

#include "Rational.h"

Rational::Rational(int num, int denom) {
    this->numerator = num;
    this->denominator = denom;
}

int Rational::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int Rational::getNumerator() {
    return this->numerator;
}

int Rational::getDenominator() {
    return this->denominator;
}

Rational Rational::add(const Rational &other) {
    int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};

}

Rational Rational::operator+(const Rational &other) const {
    int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};
}


Rational Rational::subtract(const Rational &other) {
    int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};
}

Rational Rational::operator-(const Rational &other) const {
    int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};
}

Rational Rational::multiply(const Rational &other) {
    int newNumerator = this->numerator * other.numerator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};
}

Rational Rational::operator*(const Rational &other) const {
    int newNumerator = this->numerator * other.numerator;
    int newDenominator = this->denominator * other.denominator;
    return {newNumerator, newDenominator};
}

Rational Rational::divide(const Rational &other) {
    int resultNumerator = this->numerator * other.denominator;
    int resultDenominator = this->denominator * other.numerator;
    return {resultNumerator, resultDenominator};
}

Rational Rational::operator/(const Rational &other) const {
    int resultNumerator = this->numerator * other.denominator;
    int resultDenominator = this->denominator * other.numerator;
    return {resultNumerator, resultDenominator};
}


Rational Rational::reduce() {
    int divisor = gcd(numerator, denominator);
    int reducedNumerator = numerator / divisor;
    int reducedDenomiator = denominator / divisor;
    return {reducedNumerator, reducedDenomiator};
}

Rational Rational::inverse() const {
    int aux = this->denominator;

    return {aux, this->numerator};
}

bool Rational::compare(const Rational &other) {
    if (this->denominator != other.denominator) {

        int newRational1Numerator = this->numerator * other.denominator;

        int newRational2Numerator = this->denominator * other.numerator;

        if (newRational1Numerator >= newRational2Numerator) {
            return true;
        } else {
            return false;
        }

    }

    if (this->numerator >= other.numerator) {
        return true;
    } else {
        return false;
    }
}

