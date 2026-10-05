#include <iostream>
using namespace std;

// new operator
int notes_main() {
    // ARRAYS
    // allocate memory of a data type
    // pointer initialzed with null
    int* p = NULL;
    p = new int;

    // OR
    int* p2 = new int;

    // OR initialize memory
    int* p3 = new int(25);
    float* q = new float(75.25);

    // allocate block of memory - (array) of a data type
    int* p5 = new int[10];

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

    delete[] p5;

    // arrays (again)
    // 1. declaration w/ specific size:
    int arr[10];
    int n = 10;
    int arr2[n];
    // 2. declaration w/ initialization of elements:
    int arr3[] = {10, 20, 30};
    // compiler creates an arr with size 3
    // same as `int arr[3] = {10, 20, 30};

    // 3. declaration w/ initialization of elements:
    int arr4[3] = {1, 2, 3};
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
    newJunk.func(7, 2);

    // * Operator Overloading: e.g. making `+` for string concat two strings!

    class Complex {
      private:
        int real, imag;

      public:
        Complex(int r = 0, int i = 0) {
            real = r;
            imag = i;
        }

        Complex operator+(Complex const& obj) {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        void print() { cout << real << " + i" << imag << endl; }
    };

    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // using operator +
    c3.print();

    // 2. Runtime polymorphism - achieved via Function overriding.
    class base {
      public:
        virtual void print() { cout << "print in base class" << endl; }
        void show() { cout << "show in base class" << endl; }
    };
    class derived : public base {
      public:
        // print already virtual func in derived class
        void print() { cout << "print in derived class" << endl; }
        void show() { cout << "show in derived class" << endl; }
    };

    base* bptr;
    derived d;
    bptr = &d;

    // virtual func bound at runtime
    bptr->print();

    // non-virtual func bound at compile time
    bptr->show();

    // virtual funcs are called baed on type of obj pointed TO / referenced
    // NOT the type of the pointer.
    // so bptr pointed at derived type, &d - derived class print runs
    // * but base show is NOT virtual -- so we still get base class show!

    // Virtual Funcs: member func declared in base class, overridden in derived
    // classes
    // * funcs are declared w/ `virtual` keyword
    // * useful for runtime polymorphism
    // * ensure correct func called regardless of ptr/reference type!

    // ! Rules for Virt funcs:
    // 1. can't be static/friend func of another class
    // 2. should be accessed via ptr / reference of base class type to achieve
    // run time polymorphism
    // 3. prototype must match for base <> derived classes
    // 4. virtual destructors ✅ , virtual constructors 🚫
    // 5. always defined in BASE class, overriden in derived class - (but
    // override not required)

    // virtual functions - are essentially interfaces!
    // from which derived classes must adhere to implicitly

    // vtable: table of func pointers - per class
    // vptr: ptr to vtable - maintained per obj
    // compiler adds add'l code to maintain runtime declared ptrs.
    // 1. code in every constructor - sets vptr to point to vtable of the class
    // 2. code w/ polymorphic func calls -- and we look up vptr from vtable --
    // omg..i've done this before. but in higher level code - a hash of
    // functions to be called in dynamically at runtime since we'd not know what
    // args a user passed...

    // inheritance vs polymorphism: new class inherits properties of base
    // classes
    // - re-use of code, reduce length of code in oop
    // - applies to CLASSES
    // polymorphism: performing a task multiple ways
    // - compile time poly/run-time poly
    // - applies to FUNCTIONS

    return 0;
}
