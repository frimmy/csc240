// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

// void pointer represents absence of type
// value has no type -- (and undetermined dereferencing properties)
// can be of any data type - but cannot be dereferenced

void increase(void* data, int ptrsize) {
    if (ptrsize == sizeof(char)) {
        char* ptrchar;
        // typecase data to a char pointer
        ptrchar = (char*)data;

        // increase the char stored at *ptrchar by 1
        (*ptrchar)++;
        cout << "*data points to a char" << endl;
    } else if (ptrsize == sizeof(int)) {
        int* ptrint;
        // typecast data to int ptr
        ptrint = (int*)data;

        // increase the int stored at *ptrchar by 1
        (*ptrint)++;
        cout << "*data points to an int" << endl;
    }
}
int main() {
    // declares char
    char c = 'x';

    // declare int
    int i = 10;

    // call increase function using a char and int address respectively
    increase(&c, sizeof(c));

    cout << "the new value of c is: " << c << endl;

    increase(&i, sizeof(i));
    cout << "the new value of i is: " << i << endl;

    return 0;
}
