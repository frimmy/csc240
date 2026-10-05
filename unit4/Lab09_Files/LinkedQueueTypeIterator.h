#ifndef LINKEDQUEUETYPEITERATOR_H
#define LINKEDQUEUETYPEITERATOR_H
#include "NodeType.h"
#include <stddef.h>
// A template for an iterator that implements the contract required by the
// range-based for-loop.
template <class ItemType> class LinkedQueueTypeIterator {
  public:
    // Customize the constructor to work with the ADT.
    LinkedQueueTypeIterator(NodeType<ItemType>* start, int loc);
    ItemType& operator*();
    // Customize to return the proper iterator class.
    LinkedQueueTypeIterator<ItemType>& operator++();
    // Customize to receive the correct Iterator class.
    bool operator!=(const LinkedQueueTypeIterator<ItemType>& it) const;

  private:
    // The start of the linked list.
    NodeType<ItemType>* item;
    int location;
};

// Implementation must be in header for templates
template <class ItemType>
LinkedQueueTypeIterator<ItemType>::LinkedQueueTypeIterator(
    NodeType<ItemType>* start, int loc) {
    this->item = start;
    location = loc;
}

template <class ItemType>
ItemType& LinkedQueueTypeIterator<ItemType>::operator*() {
    return item->info;
}

template <class ItemType>
LinkedQueueTypeIterator<ItemType>&
LinkedQueueTypeIterator<ItemType>::operator++() {
    item = item->next;
    location += 1;
    return *this;
}

template <class ItemType>
bool LinkedQueueTypeIterator<ItemType>::operator!=(
    const LinkedQueueTypeIterator<ItemType>& it) const {
    return location != it.location;
}

#endif
