// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

int main() {
    char a;
    char* b;
    char** c;
    a = 'g';
    b = &a; // b points to a char data type that stores 'g'
    c = &b; // c points to the pointer b
}
