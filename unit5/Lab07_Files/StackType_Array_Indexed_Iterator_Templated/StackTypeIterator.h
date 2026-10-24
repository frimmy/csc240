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
// This iterator returns indices to be used with operator[] for an authentic
// variation.
template <typename ItemType> class StackTypeIterator {
  public:
    // Constructor to initialize the iterator with a location
    StackTypeIterator(int location);

    // Dereference operator for the iterator - returns the index
    int operator*();

    // Pre-increment operator
    StackTypeIterator<ItemType>& operator++();

    // Inequality operator
    bool operator!=(const StackTypeIterator<ItemType>& it) const;

  private:
    int index;
};

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

template <typename ItemType>
StackTypeIterator<ItemType>::StackTypeIterator(int location) {
    this->index = location;
}

template <typename ItemType> int StackTypeIterator<ItemType>::operator*() {
    return index;
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
