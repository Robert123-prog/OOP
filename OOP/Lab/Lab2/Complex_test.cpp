//
// Created by user on 18-Mar-24.
//

#include "Complex.h"
#include <cassert>
#include <cmath>

using namespace std;

#include <string>

void testAllC() {
    Complex c1(3, 5);
    Complex c2(4, 7);

    assert(c1.getReal() == 3);
    assert(c2.getImaginary() == 7);

    //TEST add
    Complex res = c1.add(c2);
    assert(res.getReal() == 7);
    assert(res.getImaginary() == 12);

    //TEST subtract
    Complex res2 = c1.subtract(c2);
    assert(res2.getReal() == -1);
    assert(res2.getImaginary() == -2);

    //TEST multiply
    Complex res3 = c1.multiply(c2);
    assert(res3.getReal() == -23);
    assert(res3.getImaginary() == 41);

    //TEST divide
    Complex res4 = c1.divide(c2);
    assert(res4.getReal() == 47 / 65);
    assert(res4.getImaginary() == 1 / 65);

    //TEST absolute
    assert(c1.absolute() == sqrt(34));

    //TEST compute polar for c1, considering c1.real > 0
    double theta = atan(c1.getImaginary() / c1.getReal());
    double res5 = c1.absolute() * (cos(theta) + sqrt(-1) * sin(theta));
    assert(c1.computePolar() == res5);

    //TEST text
    assert(c1.text() == "3 + 5i");


}
int main() {
    testAllC();
    return 0;
}
