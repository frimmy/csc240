// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

int main() {
    // Declare array
    int val[3] = {5, 10, 20};

    // declare pointer var
    int* ptr;

    // assign address of val[0] to ptr
    // we can use ptr=&val[0]; - tis the same

    ptr = val;
    cout << "Elems of array are: ";
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
    return 0;
}
