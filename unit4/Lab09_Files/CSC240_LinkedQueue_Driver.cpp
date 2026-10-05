//============================================================================
// Name        : CSC240_Queue_Linked.cpp
// Author      : Adrian Frimpong
// Version     :10/4/2026
// Copyright   : Your copyright notice
// Description : Practice with the Linked Queue and Templates
//============================================================================

// Creative Feature:
// What does your feature do? adds a const_iterator (and == for good measure)

// What concept from your AI Learning Query did it use?
// used function overloading, iterators, and templates

// What did you try that did not work?
// Tried not overloading -- and temporarily attempted to avoid duplication of my
// beginning and end statements, but this didn't work. Also thought about
// rewriting the Queue to use a sentinel node, but this would've forced all the
// existing methods to need to be rewritten.

// What would you do next if you had another week? Implement use of find or
// sorting on the queue(maybe in a future lab.)
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
    cout << "Print():" << endl;
    q.Print();

    // 2. Print the queue with an explicit iterator loop.
    cout << "Explicit iterator: ";
    for (LinkedQueueTypeIterator<int> iter = q.begin(); iter != q.end();
         ++iter) {
        cout << *iter << " ";
    }
    cout << endl << "Range-based for: ";
    // 3. Print it with a range-based for loop.
    for (int& x : q) {
        cout << x << " ";
    }
    // 4. Double every item with for (int& x : q) x = x * 2;
    cout << endl << "Doubling every item through the iterator...";
    for (int& x : q)
        x = x * 2;
    // 4b. then print it
    //   with the range-based loop and with Print().
    cout << endl << "Range-based for: ";
    for (const int& x : q)
        cout << x << " ";
    cout << endl << "Print():" << endl;
    q.Print();
    //   5. Make a single-element queue holding 42. Iterate it and report
    //   begin() != end(), which should be true.
    q.MakeEmpty();
    q.Enqueue(42);
    cout << "Single-element queue: ";
    for (int& x : q)
        cout << x << " " << endl;

    cout << "begin() != end() on one: "
         << (q.begin() != q.end() ? "true" : "false") << endl;
    //   6. Make an empty queue. Iterate it (the body must not run) and
    //   report begin() != end(), which should be false.
    q.MakeEmpty();
    cout << "Empty queue: (nothing printed)" << endl;
    for (int& x : q) {
        cout << x << " ";
    }
    cout << "begin() != end() on empty: "
         << (q.begin() != q.end() ? "true" : "false") << endl;
    cout << "begin() == end() on empty: "
         << (q.begin() == q.end() ? "true" : "false") << endl;
    cout << "Iterate a const q: ";
    LinkedQueueType<int> baseQ;
    baseQ.Enqueue(5);
    baseQ.Enqueue(7);
    baseQ.Enqueue(9);
    const LinkedQueueType<int>& const_queue = baseQ;
    for (const int& x : const_queue) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
