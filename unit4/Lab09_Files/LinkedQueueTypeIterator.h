#ifndef LINKEDQUEUETYPEITERATOR_H
#define LINKEDQUEUETYPEITERATOR_H
#include "NodeType.h"
#include <stddef.h>
// The invariant: item is a pointer to an initialized queue. Location is an
// integer that reflects the number of nodes the location(item) has traversed to
// point to the current node.

// A template for an iterator that implements the contract required by the
// range-based for-loop.
template <class ItemType, class RefType = ItemType&>
class LinkedQueueTypeIterator {
  public:
    // Customize the constructor to work with the ADT.
    LinkedQueueTypeIterator(NodeType<ItemType>* start, int loc);

    // Dereference operator for the iterator.
    RefType operator*() const;

    // Customize to return the proper iterator class.
    LinkedQueueTypeIterator<ItemType, RefType>& operator++();

    // Customize to receive the correct Iterator class.
    bool operator!=(const LinkedQueueTypeIterator<ItemType, RefType>& it) const;

    // Customize to receive the correct Iterator class.
    bool operator==(const LinkedQueueTypeIterator<ItemType, RefType>& it) const;

  private:
    // The start of the linked list.
    NodeType<ItemType>* item;
    int location;
};

// Implementation must be in header for templates
// Constructor:
// Because there is a default constructor, the precondition
// that the queue has been initialized is omitted.
template <class ItemType, class RefType>
LinkedQueueTypeIterator<ItemType, RefType>::LinkedQueueTypeIterator(
    NodeType<ItemType>* start, int loc) {
    this->item = start;
    location = loc;
}

// Function: returns the pointer reference to current node info
// Pre-condition: pointer is initialized to a node
// Post condition: return a conditional pointer reference to the node(read-only
// or mutable)
template <class ItemType, class RefType>
RefType LinkedQueueTypeIterator<ItemType, RefType>::operator*() const {
    return item->info;
}

// Function: pre-increment operator
// Pre-condition: a queue is initialized and location counts the number of nodes
// from beginning the current node is
// Post-condition: queue location is progressed to the next node
template <class ItemType, class RefType>
LinkedQueueTypeIterator<ItemType, RefType>&
LinkedQueueTypeIterator<ItemType, RefType>::operator++() {
    item = item->next;
    location += 1;
    return *this;
}

// Function: unequal operator used in iterator
// Pre-condition: a queue is initialized and location counts the number of nodes
// from beginning the current node is
// Post-condition: returns whether the comparison iterator is unequal
template <class ItemType, class RefType>
bool LinkedQueueTypeIterator<ItemType, RefType>::operator!=(
    const LinkedQueueTypeIterator<ItemType, RefType>& it) const {
    return location != it.location;
}

// Function: equal operator used in iterator
// Pre-condition: a queue is initialized and location counts the number of nodes
// from beginning the current node is
// Post-condition: returns whether the comparison iterator is equal
template <class ItemType, class RefType>
bool LinkedQueueTypeIterator<ItemType, RefType>::operator==(
    const LinkedQueueTypeIterator<ItemType, RefType>& it) const {
    return location == it.location;
}

#endif
