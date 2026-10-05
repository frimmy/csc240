// Header file for Queue ADT.
// Template version of the Linked Queue using a front and rear pointer.
// Invariant: rear->next points at the first element, with length reflecting the
// number of elements in the queue. Rear reflects the element most recently
// added to the queue.
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "LinkedQueueTypeIterator.h"
#include "NodeType.h"
#include <cstddef>
#include <iostream>
#include <new>

class FullQueue {};
class EmptyQueue {};
template <class ItemType> class LinkedQueueType {
  public:
    LinkedQueueType();
    // Class constructor.
    // Because there is a default constructor, the precondition
    // that the queue has been initialized is omitted.
    ~LinkedQueueType();
    // Class destructor.
    LinkedQueueType(const LinkedQueueType& anotherQue);
    // Copy constructor
    LinkedQueueType<ItemType>& operator=(const LinkedQueueType<ItemType>& rhs);
    // operator=
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void Print() const;
    // Function: Display the contents of the QueType in the console output.
    // Post: The QueType remains unchanged.
    void Rotate();
    // Function: Moves the front item to the rear
    // Post: Front is rear
    LinkedQueueTypeIterator<ItemType> begin();
    LinkedQueueTypeIterator<ItemType, const ItemType&> begin() const;

    LinkedQueueTypeIterator<ItemType> end();
    LinkedQueueTypeIterator<ItemType, const ItemType&> end() const;

  private:
    NodeType<ItemType>* rear;
    int length = 0;
};

template <class ItemType> void LinkedQueueType<ItemType>::Print() const {
    if (IsEmpty()) {
        std::cout << "already empty" << std::endl;
        return;
    }
    std::cout << "Front:";
    for (const auto& i : *this) {
        std::cout << i << " ";
    }
    std::cout << ":Rear" << std::endl;
}

// Class constructor.
// Post:  rear set to NULL.
template <class ItemType> LinkedQueueType<ItemType>::LinkedQueueType() {
    rear = nullptr;
    // rear->next = rear;
    length = 0;
}

template <class ItemType>
void LinkedQueueType<ItemType>::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
    NodeType<ItemType>* tempPtr;
    NodeType<ItemType>* curr;

    if (!IsEmpty()) {
        curr = rear->next;
        // sever the tie
        rear->next = nullptr;
        while (curr != nullptr) {
            tempPtr = curr;
            curr = tempPtr->next;
            delete tempPtr;
        }
    }
    rear = nullptr;
    length = 0;
}

// Class destructor.
template <class ItemType> LinkedQueueType<ItemType>::~LinkedQueueType() {
    MakeEmpty();
}

template <class ItemType>
bool LinkedQueueType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType<ItemType>* location;
    try {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    } catch (std::bad_alloc&) {
        return true;
    }
}

template <class ItemType>
bool LinkedQueueType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (length == 0);
}

template <class ItemType>
void LinkedQueueType<ItemType>::Enqueue(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.

{
    if (IsFull())
        throw FullQueue();
    else {
        NodeType<ItemType>* newNode = new NodeType<ItemType>;
        newNode->info = newItem;
        if (rear == nullptr) {
            newNode->next = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
        }
        rear = newNode;
        length++;
    }
}

template <class ItemType>
void LinkedQueueType<ItemType>::Dequeue(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else {
        NodeType<ItemType>* tempPtr;
        tempPtr = rear->next;
        item = tempPtr->info;
        rear->next = tempPtr->next;
        if (length == 1) {
            rear = nullptr;
        }
        delete tempPtr;
        length--;
    }
}

template <class ItemType>
LinkedQueueType<ItemType>::LinkedQueueType(const LinkedQueueType& anotherQue) {
    NodeType<ItemType>* ptr1;
    NodeType<ItemType>* ptr2;
    NodeType<ItemType>* front;

    if (anotherQue.rear == nullptr)
        rear = nullptr;
    else {
        length = 0;
        ptr1 = anotherQue.rear->next;
        front = new NodeType<ItemType>;
        front->info = ptr1->info;
        ptr1 = ptr1->next;
        rear = ptr2 = front;
        length++;
        while (ptr1 != anotherQue.rear->next) {
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            rear = ptr2;
            ptr1 = ptr1->next;
            length++;
        }
        ptr2->next = front;
    }
}
template <class ItemType>
LinkedQueueType<ItemType>&
LinkedQueueType<ItemType>::operator=(const LinkedQueueType<ItemType>& rhs) {
    NodeType<ItemType>* ptr1;
    NodeType<ItemType>* ptr2;
    NodeType<ItemType>* front;

    if (this == &rhs)
        return *this;
    MakeEmpty();
    if (rhs.rear != nullptr) {

        ptr1 = rhs.rear->next;
        front = new NodeType<ItemType>;
        front->info = ptr1->info;
        ptr1 = ptr1->next;
        rear = ptr2 = front;
        length++;
        while (ptr1 != rhs.rear->next) {
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            rear = ptr2;
            ptr1 = ptr1->next;
            length++;
        }
        ptr2->next = front;
    }
    return *this;
}

// Function: Moves the front item to the rear
// Post: Front is rear
template <class ItemType> void LinkedQueueType<ItemType>::Rotate() {
    if (!IsEmpty()) {
        NodeType<ItemType>* ptr = rear->next;
        rear = ptr;
    }
}
// Function: begin method for adhering to interator interface
// pre-condition: Queue is initialized
// post-condition: Returns iterator reference at beginning of queue
template <class ItemType>
LinkedQueueTypeIterator<ItemType> LinkedQueueType<ItemType>::begin() {
    // start at "beginning" which is rear->next
    NodeType<ItemType>* begin_ptr = rear != nullptr ? rear->next : nullptr;
    LinkedQueueTypeIterator<ItemType> it(begin_ptr, 0);
    return it;
}
template <class ItemType>
LinkedQueueTypeIterator<ItemType, const ItemType&>
LinkedQueueType<ItemType>::begin() const {
    // start at "beginning" which is rear->next
    NodeType<ItemType>* begin_ptr = rear != nullptr ? rear->next : nullptr;
    LinkedQueueTypeIterator<ItemType, const ItemType&> it(begin_ptr, 0);
    return it;
}

// Function: end method for adhering to interator interface
// pre-condition: Queue is initialized
// post-condition: Returns iterator reference at end of queue
template <class ItemType>
LinkedQueueTypeIterator<ItemType> LinkedQueueType<ItemType>::end() {
    NodeType<ItemType>* end_ptr = rear != nullptr ? rear->next : nullptr;
    LinkedQueueTypeIterator<ItemType> it(end_ptr, length);
    return it;
}

template <class ItemType>
LinkedQueueTypeIterator<ItemType, const ItemType&>
LinkedQueueType<ItemType>::end() const {
    NodeType<ItemType>* end_ptr = rear != nullptr ? rear->next : nullptr;
    LinkedQueueTypeIterator<ItemType, const ItemType&> it(end_ptr, length);
    return it;
}
#endif
