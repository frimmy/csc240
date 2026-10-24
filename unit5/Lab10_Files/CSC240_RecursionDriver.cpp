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

int NumPaths(int row, int col, int n) {
    if (row == n || col == n) {
        return 1;
    } else {
        return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
    }
}

int main() {
    cout << NumPaths(0, 0, 4);
    return 0;
}
