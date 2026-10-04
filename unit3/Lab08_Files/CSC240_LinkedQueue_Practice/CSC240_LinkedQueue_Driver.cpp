//============================================================================
// Name        : CSC240_Queue_Linked.cpp
// Author      : Adrian Frimpong
// Version     : 9/27/2026
// Copyright   : Your copyright notice
// Description : Practice with the Linked Queue and Templates
//============================================================================

// Creative Feature:
// What does your feature do? Rotates the queue so the front is at the rear
// What concept from your AI Learning Query did it use? Used concept of
// safe checking (so we don't operate on empty queue).
// What did you try that did not work? n/a -- was pretty trivial after
// everything else was addressed. What would you do next if you had another
// week? directional rotation and rotations by a provided number

#include "QueType.h"
#include <iostream>
using namespace std;

int main() {
    LinkedQueType<int> q;
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
    cout << numFront << endl;
    q.Dequeue(numFront);
    cout << numFront << endl;
    LinkedQueType<int> q2(q);
    q.Print();
    q2.Print();
    q.Dequeue(numFront);
    cout << numFront << endl;
    q.Print();
    q2.Print();
    LinkedQueType<int> q3 = q2;
    cout << "Empty q3 " << endl;
    q3.MakeEmpty();
    q3.Print();
    q3 = q2;
    q3.Print();
    q3.Dequeue(numFront);
    cout << numFront << endl;
    q3.Print();
    q3.Rotate();
    q3.Print();
    LinkedQueType<int> q4;
    q4.Enqueue(1);
    q4.Dequeue(numFront);
    // deque from empty
    try {
        q4.Dequeue(numFront);
    } catch (EmptyQueue) {
        cout << "queue is empty!";
    }
    return 0;
}
