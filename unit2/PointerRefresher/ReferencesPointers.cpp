// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

// pass-by-value
int square1(int n) {
    // address of n in square1() isn't the same as n1 in main()
    cout << "addresss of n1 in square(): " << &n << "\n";

    // clone modified inside the function
    n *= n;
    return n;
}

// Pass by reference w/ Ptr arguments
void square2(int* n) {
    // Address of n in square2() is the same as n2 in main()
    cout << "address of n2 in square2(): " << n << "\n";

    // explicit de-referencing to get the value pointed-to
    *n *= *n;
}

// Pass by reference w/ reference arguments
void square3(int& n) {
    // address of n in square3() is the same as n3 in main()
    cout << "address of n3 in square3(): " << &n << "\n";

    // implicit de-referencing (without '*')
    n *= n;
}

int main() {
    // call by value
    int n1 = 8;
    cout << "address of n1 in main(): " << &n1 << endl;
    cout << "Square of n1: " << square1(n1) << endl;
    cout << "No change in n1: " << n1 << endl;

    // call be reference w/ pointer arguments
    int n2 = 8;
    cout << "address of n2 in main(): " << &n2 << endl;
    square2(&n2);
    cout << "Square of n2: " << n2 << endl;
    cout << "Change reflected in n2: " << n2 << endl;

    // call by ref w/ ref argument
    int n3 = 8;
    cout << "address of n3 in main(): " << &n3 << endl;
    square3(n3);
    cout << "Square of n3: " << n3 << "\n";
    cout << "Change reflected in n3: " << n3 << endl;

    return 0;
}
