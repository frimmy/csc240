// Test driver
#include "frac.h"
#include <fstream>
#include <iostream>
#include <string>
int main() {

    FractionType one;
    FractionType two;
    one.Initialize(2, 3);
    two.Initialize(4, 5);
    FractionType three = one + two;
    three.print(cout);     // Implement this function
    cout << three << endl; // Implement this function

    FractionType x;
    FractionType y;
    x.Initialize(1, 3);
    y.Initialize(2, 3);
    FractionType z = x + y;
    cout << z << endl;

    // Test the other overloaded operators: operator-, operator*, operator/
    // here.
    FractionType a;
    FractionType b;
    a.Initialize(1, 3);
    b.Initialize(2, 3);
    FractionType c = a - b;
    cout << c << endl;

    FractionType d;
    FractionType e;
    d.Initialize(1, 3);
    e.Initialize(2, 3);
    FractionType f = d * e;
    cout << f << endl;

    FractionType g;
    FractionType h;
    g.Initialize(1, 3);
    h.Initialize(2, 3);
    FractionType i = g / h;
    cout << i << endl;

    // Extra Credit +2: reduce*********************
    z.reduce();
    cout << z << endl;

    FractionType reduced;
    reduced.Initialize(15, 20);
    reduced.reduce();
    cout << reduced << endl;
    //********************************************
}
