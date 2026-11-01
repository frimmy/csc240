//============================================================================
// Name        : CSC240_RecursionDriver.cpp
// Author      : Adrian Frimpong
// Date        : 10/25/2026
// Recursive
//============================================================================

//============================================================================
// AI Feature:
// What does your feature do?
// Adds a memo-cache profiler
//
// What concept from your AI Learning Query did it use?
// It used the concept of how using memo applies how the runtime of using the
// memo approaches O(n^2) time
//
// What did you try that did not work?
// Tried intializing table within each call (as opposed to once outside). This
// defeated the purpose of using a memo since I was creating a new one w/ each
// call.
//
// What would you do next if you had another week?
// Try exploring how to approach numpaths iteratively

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

void printNumCalls(long long& calls, string label = "Num calls: ") {
    cout << label << calls << endl;
    calls = 0;
}
void printNumCalls(int& calls, string label = "Num calls: ") {
    cout << label << calls << endl;
    calls = 0;
}
void printMemoStats(long long& total, long long& base, long long& hits,
                    long long& misses) {
    cout << "Total Calls:  " << total << "\n"
         << "  ├─ Base Cases:   " << base << "\n"
         << "  ├─ Cache Hits:   " << hits << " (subtrees pruned)\n"
         << "  └─ Cache Misses: " << misses << " (unique cells computed)\n";

    if (hits + misses > 0) {
        double hitRate = (100.0 * hits) / (hits + misses);
        cout << "Interior Cache Hit Rate: " << hitRate << "%\n";
    }
    cout << "Resetting counters...\n\n";

    total = base = hits = misses = 0;
}
int origNumcalls = 0;
// runtime: O(2^N)
int OrigNumPaths(int row, int col, int n) {
    origNumcalls++;
    int result;
    if (row == n || col == n) {
        result = 1;
    } else {
        result = OrigNumPaths(row + 1, col, n) + OrigNumPaths(row, col + 1, n);
    }
    return result;
}
// function declaration
// Invariant: Base Cases + Cache Hits + Cache Misses equals the Total Calls
// Pre-condition: a Grid of N is initialized
// Post-condition: the total num of paths from start row, col is computed
// runtime: O(N^2)
int RecurseNumPaths(int row, int col, int n, int** gridPaths);

long long recurseNumCalls, baseCaseHits, memoHits, memoMisses = 0;
int NumPaths(int row, int col, int n) {
    recurseNumCalls = 0;
    baseCaseHits = 0;
    memoHits = 0;
    memoMisses = 0;

    // early return for when we initialize starting point on grid along
    // edge.
    if (row >= n || col >= n) {
        return 1;
    }
    int** gridPaths = new int*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        gridPaths[i] = new int[n - 1]();
    }
    int result = RecurseNumPaths(row, col, n, gridPaths);
    // clean up memory
    for (int i = 0; i < n - 1; i++) {
        delete[] gridPaths[i];
    }
    delete[] gridPaths;
    return result;
}

int RecurseNumPaths(int row, int col, int n, int** gridPaths) {
    recurseNumCalls++;
    if (row >= n || col >= n) {
        baseCaseHits++;
        return 1;
    } else {
        if (gridPaths[row - 1][col - 1] != 0) {
            memoHits++;
            return gridPaths[row - 1][col - 1];
        }
        memoMisses++;
        gridPaths[row - 1][col - 1] =
            RecurseNumPaths(row + 1, col, n, gridPaths) +
            RecurseNumPaths(row, col + 1, n, gridPaths);
        return gridPaths[row - 1][col - 1];
    }
}

float NewtonsSqrtRecurse(float x, float a, float tolerance) {
    // base case
    if (abs(a * a - x) <= tolerance) {
        return a;
    } else {
        // recurse
        a = (a + x / a) / 2;
        return NewtonsSqrtRecurse(x, a, tolerance);
    }
}
float NewtonsSqrt(float x, float tolerance = .75) {
    float a = x;
    return NewtonsSqrtRecurse(x, a, tolerance);
}
float IterativeNewtonsSqrt(float x, float tolerance = .75) {
    float a = x;
    while (abs(a * a - x) > tolerance)
        a = (a + x / a) / 2;
    return a;
}

int main() {
    cout << "orig numpaths for 4x4" << endl;
    cout << OrigNumPaths(1, 1, 4) << endl;
    printNumCalls(origNumcalls, "Original numpaths calls: ");

    cout << "Memoized Numpaths for 4x4 == 20" << endl;
    cout << NumPaths(1, 1, 4) << endl;
    printNumCalls(recurseNumCalls, "recursive num path calls: ");

    cout << "orig numpaths for 5x5" << endl;
    cout << OrigNumPaths(1, 1, 5) << endl;
    printNumCalls(origNumcalls, "Original numpaths calls: ");

    cout << "Memoized Numpaths for 5x5 == 70" << endl;
    cout << NumPaths(1, 1, 5) << endl;
    printMemoStats(recurseNumCalls, baseCaseHits, memoHits, memoMisses);

    cout << "Memoized Numpaths for 10x10 == 48620" << endl;
    cout << NumPaths(1, 1, 10) << endl;
    printMemoStats(recurseNumCalls, baseCaseHits, memoHits, memoMisses);

    cout << "Newton SQRT: 4 ~= 2" << endl;
    cout << NewtonsSqrt(4, .001) << endl;
    cout << "Newton SQRT: 9 ~= 3" << endl;
    cout << NewtonsSqrt(9, 1e-18) << endl;
    cout << "Newton SQRT: 21 ~= 4" << endl;
    cout << NewtonsSqrt(21, .001) << endl;
    cout << "Iterative Newton SQRT: 21 ~= 4" << endl;
    cout << IterativeNewtonsSqrt(21, .001) << endl;
    return 0;
}
