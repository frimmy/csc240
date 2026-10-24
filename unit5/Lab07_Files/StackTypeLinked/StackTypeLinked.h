#ifndef STACK_H
#define STACK_H
#include <cmath>
#include <iostream>
#include <new>

class FullStack {};
class EmptyStack {};

template <class ItemType> struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};

template <class ItemType> class StackTypeLinked {
  public:
    StackTypeLinked();
    ~StackTypeLinked();
    // Copy Constructor
    StackTypeLinked(const StackTypeLinked& rhs);
    // operator=
    StackTypeLinked& operator=(const StackTypeLinked& rhs);
    void Push(ItemType);
    void Pop();
    ItemType Top();
    bool IsEmpty() const;
    bool IsFull() const;
    void Print();
    int StackSum();
    void PowerStack();
    void MakeEmpty();

  private:
    NodeType<ItemType>* topPtr;
    void PowerStackHelper(int topValue);
};
// Operator=
template <class ItemType>
StackTypeLinked<ItemType>&
StackTypeLinked<ItemType>::operator=(const StackTypeLinked<ItemType>& rhs) {
    std::cout << "operator= called." << std::endl;
    if (this == &rhs) { // don't allow list = list;
        return *this;
    } else {
        NodeType<ItemType>* location = rhs.topPtr;
        int length = 0;
        while (location != nullptr) {
            length++;
            location = location->next;
        }
        ItemType* items = new ItemType[length];
        location = rhs.topPtr;
        int index = 0;
        while (location != nullptr) {
            items[index] = location->info;
            location = location->next;
            index++;
        }
        location = rhs.topPtr;
        topPtr = nullptr;
        for (int i = length - 1; i >= 0; i--) {
            Push(items[i]);
        }
    }
    return *this;
}
// Copy Constructor
template <class ItemType>
StackTypeLinked<ItemType>::StackTypeLinked(
    const StackTypeLinked<ItemType>& rhs) {
    std::cout << "Copy Constructor called." << std::endl;
    NodeType<ItemType>* location = rhs.topPtr;
    int length = 0;
    while (location != nullptr) {
        length++;
        location = location->next;
    }
    ItemType* items = new ItemType[length];
    location = rhs.topPtr;
    int index = 0;
    while (location != nullptr) {
        items[index] = location->info;
        location = location->next;
        index++;
    }
    location = rhs.topPtr;
    topPtr = nullptr;
    for (int i = length - 1; i >= 0; i--) {
        Push(items[i]);
    }
}

template <class ItemType> void PrintRec(NodeType<ItemType>* top) {
    // Base Case
    if (top == nullptr)
        return;
    // Recursive Case
    else {
        std::cout << top->info << std::endl;
        PrintRec(top->next);
    }
}

// A recursive print function for the linked stack.
// O(n) where n is the size of the stack.
template <class ItemType> void StackTypeLinked<ItemType>::Print() {
    std::cout << "Top:\n";
    PrintRec(topPtr);
    std::cout << ":Bottom\n";
}

// Adds newItem to the top of the stack.
// Stack is bounded by size of memory.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.
template <class ItemType>
void StackTypeLinked<ItemType>::Push(ItemType newItem) {
    if (IsFull())
        throw FullStack();
    else {
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        location->info = newItem;
        location->next = topPtr;
        topPtr = location;
    }
}

template <class ItemType>
void StackTypeLinked<ItemType>::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
    if (IsEmpty())
        throw EmptyStack();
    else {
        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}
template <class ItemType>

// Pre: Stack is initialized.
// Post: Stack is empty; all elements have been deallocated.
void StackTypeLinked<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    NodeType<ItemType>* curr;

    if (!IsEmpty()) {
        curr = topPtr;
        // sever the tie
        topPtr = nullptr;
        while (curr != nullptr) {
            tempPtr = curr;
            curr = tempPtr->next;
            delete tempPtr;
        }
    }
    topPtr = nullptr;
}

template <class ItemType>
ItemType StackTypeLinked<ItemType>::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}

// Function: Returns the sum of the stack
// Precondition: Stack is initialized, and the stack contains items (integers).
// Postcondition: Stack is unchanged
// Invariant: Stack is unchanged after calls to StackSum.
// each recursive frame pushes back the exact element it popped, so unwinding
// restores every element to its original position.
template <class ItemType> int StackTypeLinked<ItemType>::StackSum() {
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
template <class ItemType> void StackTypeLinked<ItemType>::PowerStack() {
    if (topPtr != nullptr && topPtr->next != nullptr) {
        PowerStackHelper(Top());
    } else {
        std::cout << "Not enough elems to call PowerStack!" << std::endl;
    }
}

// Private helper that enables passing the top value through recursive calls
// Pre
template <class ItemType>
void StackTypeLinked<ItemType>::PowerStackHelper(int topValue) {
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

template <class ItemType>
StackTypeLinked<ItemType>::StackTypeLinked() // Class constructor.
{
    topPtr = nullptr;
}

template <class ItemType>
bool StackTypeLinked<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType<ItemType>* location;
    try {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

template <class ItemType>
StackTypeLinked<ItemType>::~StackTypeLinked()
// Post: stack is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (topPtr != nullptr) {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType> bool StackTypeLinked<ItemType>::IsEmpty() const {
    return (topPtr == nullptr);
}

#endif
