//============================================================================
// Name        : CSC240_RecursionInefficiency.cpp
// Author      : Ivan Temesvari
// Date        : 2/22/2023
// Recursive Efficiency?
//============================================================================

#include <chrono>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int powerOf2(int base, int exponent) {
    // Base case--stops the recursion.
    if (exponent == 0) {
        return 1;
    }
    // Recursive case--makes another call to the powerOf2 function.
    else {
        return base * powerOf2(base, --exponent);
    }
}

int main() {
    // Timers
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;
    // Recursion
    int base = 2, exponent = 20;
    start = chrono::system_clock::now();
    cout << powerOf2(base, exponent) << endl;
    end = chrono::system_clock::now();
    chrono::duration<float> elapsed = end - start;
    cout << "Total time in seconds (recursion): " << elapsed.count() << endl;
    // Or for loop
    start = chrono::system_clock::now();
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    cout << result << endl;
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Total time in seconds (loop): " << elapsed.count() << endl;
    // Bit shift
    start = chrono::system_clock::now();
    cout << (2 << 19) << endl;
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Total time in seconds (bit shift): " << elapsed.count() << endl;
    // math library pow function
    start = chrono::system_clock::now();
    cout << pow(2, 20) << endl;
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Total time in seconds (pow): " << elapsed.count() << endl;

    return 0;
}
