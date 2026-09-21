#ifndef STACK_H
#define STACK_H
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
    friend bool Identical(const StackTypeLinked<ItemType>& stack1,
                          const StackTypeLinked<ItemType>& stack2) {

        // make copies for passing to recursive helper
        StackTypeLinked<ItemType> copyStack1(stack1);
        StackTypeLinked<ItemType> copyStack2(stack2);

        return IdenticalRecurse(copyStack1, copyStack2);
    }

    static bool IdenticalRecurse(StackTypeLinked<ItemType>& stack1,
                                 StackTypeLinked<ItemType>& stack2) {

        // base case
        if (stack1.IsEmpty() && stack2.IsEmpty())
            return true;
        if (stack1.IsEmpty() || stack2.IsEmpty())
            return false;

        ItemType top1 = stack1.Top();
        ItemType top2 = stack2.Top();
        if (top1 != top2)
            return false;
        else {
            // pop items and recurse
            stack1.Pop();
            stack2.Pop();
            return IdenticalRecurse(stack1, stack2);
        }
    }

  private:
    NodeType<ItemType>* topPtr;
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

template <class ItemType>
void ReplaceItem(StackTypeLinked<ItemType>& stack, ItemType oldItem,
                 ItemType newItem) {
    // Base Case
    if (stack.IsEmpty())
        return;
    // Recursive Case
    else {
        ItemType top = stack.Top();
        if (top == oldItem) {
            top = newItem;
        }
        // pop top item and recurse
        stack.Pop();
        ReplaceItem(stack, oldItem, newItem);
        // after done - push the temp item back
        stack.Push(top);
    };
};

#endif
