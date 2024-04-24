#include <iostream>

//enum Weekday{
//    Monday,
//    Tuesday,
//    Wednesday,
//    Thursday,
//    Friday,
//    Saturday,
//    Sunday
//};

#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "GeometricForm.h"

using namespace std;

int main(){
    GeometricForm* g;
    Circle c(2.0);
    Square s(3.0);
    g = &c;
    g->printDescription();
    g = &s;
    g->printDescription();
    // cout << c.calculateArea() << "\n";
    // cout << s.calculateArea() << "\n";
    // c.printDescription();
    // s.printDescription();
    return 0;
}