//
// Created by user on 17-Mar-24.
//

#ifndef LAB2_RATIONAL_H
#define LAB2_RATIONAL_H


class Rational {
private:
    int numerator, denominator;

    int gcd(int a, int b);

public:
    Rational(int num, int denom);

    int getNumerator();

    int getDenominator();

    Rational add(const Rational &other);

    Rational operator+(const Rational &other) const;

    Rational operator-(const Rational &other) const;

    Rational operator*(const Rational &other) const;

    Rational operator/(const Rational &other) const;

    Rational subtract(const Rational &other);

    Rational multiply(const Rational &other);

    Rational divide(const Rational &other);

    Rational reduce();

    Rational inverse() const;

    bool compare(const Rational &other);

};


#endif //LAB2_RATIONAL_H
