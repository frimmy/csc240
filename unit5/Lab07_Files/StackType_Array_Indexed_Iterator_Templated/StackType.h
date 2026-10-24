#ifndef STACK_TYPE_H
#define STACK_TYPE_H
#include "StackTypeIterator.h"
#include <cmath>
#include <iostream>
using namespace std;

// Class specification for templated Stack ADT
// Edit: Templated version

class FullStack {};
// Exception class thrown by Push when stack is full.

class EmptyStack {};
// Exception class thrown by Pop and Top when stack is empty.

class OutOfBounds {};
// Exception class thrown by operator[] when a bad index is attempted.

template <typename ItemType> class StackType {
  public:
    StackType(int max); // max is stack size
    StackType();        // Default size is 500

    // Rest of the prototypes go here.
    bool IsFull() const;
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)

    bool IsEmpty() const;
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)

    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //     otherwise, newItem is at the top of the stack.

    void Pop();
    // Function: Removes top item from the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //     otherwise, top element has been removed from stack.

    ItemType Top();
    // Function: Returns a copy of top item on the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //     otherwise, top element has been removed from stack.
    int StackSum();
    void PowerStack();
    void MakeEmpty();

    ~StackType();
    // Destructor. Reallocate the memory reserved for ItemType* items.

    void Print();
    // Print the stack

    ItemType& operator[](int);

    StackTypeIterator<ItemType> begin();
    StackTypeIterator<ItemType> end();

  private:
    int top;
    int maxStack;    // Maximum number of stack items.
    ItemType* items; // Pointer to dynamically allocated memory.
    void PowerStackHelper(int topValue);
};

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

// Overload the operator[]
template <typename ItemType>
ItemType& StackType<ItemType>::operator[](int index) {
    if (index < 0 || index > top) {
        throw OutOfBounds();
    } else {
        return items[index];
    }
}

template <typename ItemType> StackType<ItemType>::StackType(int max) {
    maxStack = max;
    top = -1;
    items = new ItemType[maxStack];
}

template <typename ItemType> StackType<ItemType>::StackType() {
    maxStack = 500;
    top = -1;
    items = new ItemType[maxStack];
}

template <typename ItemType> bool StackType<ItemType>::IsEmpty() const {
    return (top == -1);
}

template <typename ItemType> bool StackType<ItemType>::IsFull() const {
    return (top == maxStack - 1);
}

template <typename ItemType> void StackType<ItemType>::Push(ItemType newItem) {
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

template <typename ItemType> void StackType<ItemType>::Pop() {
    if (IsEmpty())
        throw EmptyStack();
    top--;
}

template <typename ItemType> ItemType StackType<ItemType>::Top() {
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}
template <typename ItemType>
void StackType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    top = -1;
}
// Function: Returns the sum of the stack
// Precondition: Stack is initialized, and the stack contains items (integers).
// Postcondition: Stack is unchanged
// Invariant: Stack is unchanged after calls to StackSum.
// each recursive frame pushes back the exact element it popped, so unwinding
// restores every element to its original position.
template <typename ItemType> int StackType<ItemType>::StackSum() {
    // base case
    int sum = 0;
    if (!IsEmpty()) {
        ItemType currVal = Top();
        sum = currVal;
        Pop();
        sum += StackSum();
        Push(currVal);
    }
    return sum;
}
// Function: Each item is replaced with its value raised to the power of the
// value of the item below it. The bottom item is raised to the power of the
// item at the top.
// Precondition: The stack contains at least two items.
// Postcondition: The stack items are updated accordingly
template <class ItemType> void StackType<ItemType>::PowerStack() {
    if (top > 0) {
        PowerStackHelper(Top());
    } else {

        std::cout << "Not enough elems to call PowerStack!" << std::endl;
        return;
    }
}

// Private helper that enables passing the top value through recursive calls
template <class ItemType>
void StackType<ItemType>::PowerStackHelper(int topValue) {
    // base case
    int currValue = Top();
    Pop();
    int powerValue;
    if (IsEmpty()) {
        powerValue = topValue;
    } else {
        // recurse
        powerValue = Top();
        PowerStackHelper(topValue);
    }
    // add back to stack on the way up
    Push(std::pow(currValue, powerValue));
}

template <typename ItemType> StackType<ItemType>::~StackType() {
    delete[] items;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::begin() {
    StackTypeIterator<ItemType> it(0);
    // cout << "The stack iterator initializes." << endl;
    return it;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::end() {
    StackTypeIterator<ItemType> it(top + 1);
    return it;
}

template <typename ItemType> void StackType<ItemType>::Print() {
    cout << "Top:" << endl;
    if (!IsEmpty()) {
        for (int i = top; i > -1; i--) {
            cout << items[i] << endl;
        }
    }
    cout << ":Bottom" << endl;
}

#endif
