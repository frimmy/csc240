#include <iostream>
using namespace std;

// new operator
int main() {
    // ARRAYS
    // allocate memory of a data type
    // pointer initialzed with null
    int* p = NULL;
    p = new int;

    // OR
    int* p = new int;

    // OR initialize memory
    int* p = new int(25);
    float* q = new float(75.25);

    // allocate block of memory - (array) of a data type
    int* p1 = new int[10];

    // difference between allocating block of memory using new vs.
    // declaring a normal array:
    // 1. normal arrays are de-allocated by the compiler
    // 2. dynamically allocated arrays remain until deallocated by the
    // programmer! (or the program terminates)
    //

    // Delete operator
    delete p;
    delete q;
    // to free dynamic arr - do following
    // delete[] pointer-variable

    delete[] p1;

    // arrays (again)
    // 1. declaration w/ specific size:
    int arr[10];
    int n = 10;
    int arr2[n];
    // 2. declaration w/ initialization of elements:
    int arr[] = {10, 20, 30};
    // compiler creates an arr with size 3
    // same as `int arr[3] = {10, 20, 30};

    // 3. declaration w/ initialization of elements:
    int arr[3] = {1, 2, 3};
    // compiler creates arr of size 6 and first 3 elements

    // Polymorphism
    // two types: compile time vs. Run time polymorphism
    // 1. Compile Time: achieved via func overloading/operator overloading

    // * func overloading: multiple functions w/ same name BUT DIFF params
    // ** can occur via: diff num of params OR type of params
    class Junk {
      public:
        // func with 1 int
        void func(int x) { cout << "value of x is " << x << endl; }

        // func w/ same name but 1 double param
        void func(double x) { cout << "value of x is " << x << endl; }
        // func w/ same name and TWO int params
        void func(int x, int y) {
            cout << "value of x and y s " << x << ", " << y << endl;
        }
    };
    Junk newJunk;
    newJunk.func(7);
    newJunk.func(7.0);
    newJunk.func(7.0, 2.0);
    return 0;
}
