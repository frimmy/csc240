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

// function declaration
int RecurseNumPaths(int row, int col, int n, int** gridPaths);
int NumPaths(int row, int col, int n) {
    int** gridPaths = new int*[n];
    for (int i = 0; i < n; i++) {
        gridPaths[i] = new int[n]();
    }
    int result = RecurseNumPaths(row, col, n, gridPaths);
    // clean up memory
    for (int i = 0; i < n; i++) {
        delete[] gridPaths[i];
    }
    delete[] gridPaths;
    return result;
}
int RecurseNumPaths(int row, int col, int n, int** gridPaths) {
    if (row == n || col == n) {
        return 1;
    } else {
        if (gridPaths[row][col] != 0) {
            return gridPaths[row][col];
        }
        gridPaths[row][col] =
            NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
        return gridPaths[row][col];
    }
}

int NewtonsSqrtRecurse(int x, float a) {
    float tolerance = .75;
    // base case
    if (abs(a * a - x) <= tolerance) {
        return a;
    } else {
        // recurse
        a = (a + x / a) / 2;
        return NewtonsSqrtRecurse(x, a);
    }
}
int NewtonsSqrt(int x) {
    float a = x;
    return NewtonsSqrtRecurse(x, a);
}

int main() {
    cout << "Numpaths for 4x4 == 20" << endl;
    cout << NumPaths(1, 1, 4) << endl;
    cout << "Numpaths for 5x5 == 70" << endl;
    cout << NumPaths(1, 1, 5) << endl;
    cout << "Newton SQRT: 4 = 2" << endl;
    cout << NewtonsSqrt(4) << endl;
    cout << "Newton SQRT: 9 = 3" << endl;
    cout << NewtonsSqrt(9) << endl;
    cout << "Newton SQRT: 9 = 3" << endl;
    cout << NewtonsSqrt(9) << endl;
    cout << "Newton SQRT: 21 = 4" << endl;
    cout << NewtonsSqrt(21) << endl;
    return 0;
}
