#ifndef STACK_TYPE_H
#define STACK_TYPE_H
#include "StackTypeIterator.h"
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

    ~StackType();
    // Destructor. Reallocate the memory reserved for ItemType* items.

    void Print();
    // Print the stack

    ItemType& operator[](int) const;

    StackTypeIterator<ItemType> begin();
    StackTypeIterator<ItemType> end();

    friend bool Identical(const StackType<ItemType>& stack1,
                          const StackType<ItemType>& stack2) {
        int idx = 0;
        if (stack1.top != stack2.top) {
            return false;
        }
        while (idx <= stack1.top) {
            if (stack1[idx] != stack2[idx]) {
                return false;
            }
            idx++;
        }
        return true;
    }

  private:
    int top;
    int maxStack;    // Maximum number of stack items.
    ItemType* items; // Pointer to dynamically allocated memory.
};

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

// Overload the operator[]
template <typename ItemType>
ItemType& StackType<ItemType>::operator[](int index) const {
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

template <typename ItemType> StackType<ItemType>::~StackType() {
    delete[] items;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::begin() {
    StackTypeIterator<ItemType> it(0, items);
    cout << "The stack iterator initializes." << endl;
    return it;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::end() {
    StackTypeIterator<ItemType> it(top + 1, items);
    return it;
}

template <typename ItemType> void StackType<ItemType>::Print() {
    cout << "Top:" << endl;
    if (!IsEmpty()) {
        for (StackTypeIterator<ItemType> it = begin(); it != end(); ++it) {
            cout << *it << endl;
        }
    }
    cout << ":Bottom" << endl;
}

template <typename ItemType>
void ReplaceItem(StackType<ItemType>& stack, ItemType oldItem,
                 ItemType newItem) {
    for (auto& i : stack) {
        if (i == oldItem) {
            i = newItem;
        }
    }
}

#endif
