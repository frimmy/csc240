// Test driver
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "StackTypeLinked.h"

using namespace std;

int main() {
    // Test the Print function.
    StackTypeLinked<char> myStack;
    myStack.Push('A');
    myStack.Push('K');
    myStack.Push('G');
    myStack.Push('K');
    myStack.Print();
    // Test copy constructor
    StackTypeLinked<char> newStack(myStack);
    newStack.Print();
    StackTypeLinked<char> anotherStack;
    anotherStack.Push('B');
    anotherStack.Push('C');
    anotherStack.Push('D');
    anotherStack.Push('E');
    anotherStack.Print();
    // Test operator=
    anotherStack = newStack;
    anotherStack.Print();
    cout << "====== Test ReplaceItem ======" << endl;
    ReplaceItem(myStack, 'A', 'Z');
    myStack.Print();
    return 0;
}
