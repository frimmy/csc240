//============================================================================
// Name        : CSC240_Queue_Linked.cpp
// Author      : Adrian Frimpong
// Version     :10/4/2026
// Copyright   : Your copyright notice
// Description : Practice with the Linked Queue and Templates
//============================================================================

// Creative Feature:

#include "LinkedQueueType.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Enqueue 8 6 7 5 3 0 9, then call Print().
    LinkedQueueType<int> q;
    q.Enqueue(8);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(5);
    q.Enqueue(3);
    q.Enqueue(0);
    q.Enqueue(9);
    q.Print();
    int numFront;
    q.Dequeue(numFront);

    // 2. Print the queue with an explicit iterator loop.
    cout << "Explicit iterator";
    for (LinkedQueueTypeIterator<int> iter = q.begin(); iter != q.end();
         ++iter) {
        cout << *iter << " ";
    }
    // 3. Print it with a range-based for loop.
    for (int& x : q) {
        cout << x << " ";
    }
    // 4. Double every item with for (int& x : q) x = x * 2;
    for (int& x : q)
        x = x * 2;
    // 4b. then print it
    //   with the range-based loop and with Print().
    cout << endl << "Range-based print:";
    for (int& x : q)
        cout << x << " ";
    cout << endl;
    q.Print();
    //   5. Make a single-element queue holding 42. Iterate it and report
    //   begin() != end(), which should be true.
    q.MakeEmpty();
    q.Enqueue(42);
    for (int& x : q)
        cout << x << " ";

    cout << "Should be true(or 1): " << (q.begin() != q.end()) << endl;
    //   6. Make an empty queue. Iterate it (the body must not run) and
    //   report begin() != end(), which should be false.
    q.MakeEmpty();
    cout << "Print empty queue...(should be empty): " << endl;
    for (int& x : q) {
        cout << x << " ";
    }
    return 0;
}
