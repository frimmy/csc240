// Test driver
// Ivan Temesvari
// Updated operator[]
// 2/17/2022
// Templated version

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "StackType.h"

using namespace std;

int main() {
    StackType<int> myStack;
    myStack.Push(2);
    myStack.Push(5);
    myStack.Push(3);
    myStack.Print();
    cout << "StackSum: " << myStack.StackSum() << endl;
    cout << "Verify stack is restored:" << endl;
    myStack.Print();
    myStack.Pop();
    myStack.Pop();
    cout << "test a 1 item stack sum" << endl;
    cout << "StackSum: " << myStack.StackSum() << endl;
    cout << "Verify stack is restored:" << endl;
    myStack.Print();
    myStack.Pop();
    myStack.Push(4);
    myStack.Push(3);
    myStack.Push(2);
    myStack.Print();
    myStack.PowerStack();
    cout << "PowerStack - {2,3,4} -> {8, 81, 16}" << endl;
    myStack.Print();
    cout << "Empty stack and add lab ints" << endl;
    myStack.MakeEmpty();
    myStack.Push(6);
    myStack.Push(4);
    myStack.Push(3);
    myStack.Push(5);
    myStack.Push(2);
    cout << "PowerStack - {2, 5, 3, 4, 6} -> {32, 125, 81, 4096, 36}" << endl;
    myStack.PowerStack();
    myStack.Print();
    cout << "Empty stack to test PowerStack on one node" << endl;
    myStack.MakeEmpty();
    myStack.Push(2);
    cout << "Testing PowerStack on 1 element" << endl;
    myStack.PowerStack();
    return 0;
}
