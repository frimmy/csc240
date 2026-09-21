// C++ program illustrating pointers
#include <iostream>
using namespace std;

int main() {
    int var = 20;
    // declare pointer var
    int* ptr; // assignment happens at time of definition:
    // it'd be int* ptr = &var;
    // note data type of ptr and var MUST be same
    // and absence of * during this assignment
    ptr = &var; // we've stored memory of var to ptr

    // assigns address of a variable to a pointer
    cout << "Value at ptr = " << ptr << endl;
    cout << "Value at var = " << var << endl;
    cout << "Value at *ptr = " << *ptr << endl; // `*` accesses value of ptr

    return 0;
}
