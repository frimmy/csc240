// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

int main() {
    // Declare array
    int v[3] = {10, 100, 200};

    // declare pointer var
    int* ptr;

    // assign address of [0] to ptr
    ptr = v;

    for (int i = 0; i < 3; i++) {
        cout << "Value at ptr = " << ptr << endl;
        cout << "Value at *ptr = " << *ptr << endl;

        ptr++;
    }
    return 0;
}
