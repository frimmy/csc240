#ifndef STACKTYPEITERATOR_H
#define STACKTYPEITERATOR_H

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE
//
///////////////////////////////////////////////////////////////////////////////

// A template for an iterator that implements the contract required by the
// range-based for-loop. The iterator iterates over a templated stack.
template <typename ItemType> class StackTypeIterator {
  public:
    // Constructor to initialize the iterator with a location and pointer to
    // items
    StackTypeIterator(int location, ItemType* itemsPtr);

    // Dereference operator for the iterator.
    ItemType& operator*();

    // Pre-increment operator
    StackTypeIterator<ItemType>& operator++();

    // Inequality operator
    bool operator!=(const StackTypeIterator<ItemType>& it) const;

  private:
    int index;
    ItemType* items;
};

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

template <typename ItemType>
StackTypeIterator<ItemType>::StackTypeIterator(int location,
                                               ItemType* itemsPtr) {
    this->index = location;
    this->items = itemsPtr;
}

template <typename ItemType>
ItemType& StackTypeIterator<ItemType>::operator*() {
    return items[index];
}

template <typename ItemType>
StackTypeIterator<ItemType>& StackTypeIterator<ItemType>::operator++() {
    index++;
    return *this;
}

template <typename ItemType>
bool StackTypeIterator<ItemType>::operator!=(
    const StackTypeIterator<ItemType>& it) const {
    return index != it.index;
}

#endif
