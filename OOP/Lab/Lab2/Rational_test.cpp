//
// Created by user on 18-Mar-24.
//

#include "Rational.h"
#include <cassert>

int testGetNumerator(){
    Rational r1(3, 5);
    return r1.getNumerator();
}

int testGetDenominator(){
    Rational r1(3, 5);
    return r1.getDenominator();
}

void test_all(){
    assert(testGetNumerator() == 3);
    assert(testGetDenominator() == 5);

    //TEST add
    Rational r1(3, 5);
    Rational r2(4, 7);
    Rational result = r1.add(r2);
    assert(result.getNumerator() == 41);
    assert(result.getDenominator() == 35);

    //TEST subtract
    Rational result2 = r1.subtract(r2);
    assert(result2.getNumerator() == 1);
    assert(result2.getDenominator() == 35);

    //TEST multiply
    Rational result3 = r1.multiply(r2);
    assert(result3.getNumerator() == 12);
    assert(result3.getDenominator() == 35);

    //TEST divide
    Rational result4 = r1.divide(r2);
    assert(result4.getNumerator() == 21);
    assert(result4.getDenominator() == 20);


    //TEST reduce
    Rational r3(4, 6);
    Rational result5 = r3.reduce();
    assert(result5.getNumerator() == 2);
    assert(result5.getDenominator() == 3);

    //TEST inverse
    Rational result6 = r1.inverse();
    assert(result6.getNumerator() == 5);
    assert(result6.getDenominator() == 3);

    //TEST compare
    //compare => true if r1 > r2 else false
    assert(r1.compare(r2) == true);

}
//
//int main(){
//    test_all();
//    return 0;
//}
