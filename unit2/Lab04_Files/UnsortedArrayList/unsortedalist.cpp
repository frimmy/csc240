// This file contains the linked implementation of class
// UnsortedType.

#include "unsortedalist.h"
#include <iostream>
using namespace std;

UnsortedTypeArray::UnsortedTypeArray() // Class constructor
{
    length = 0;
    currentPos = -1;
}
// UnsortedTypeArray::~UnsortedTypeArray() // Class deconstructor
// {
//     length = 0;
//     currentPos = -1;
// }

bool UnsortedTypeArray::IsFull() const { return (length == MAX_ITEMS); }
int UnsortedTypeArray::GetLength() const { return length; }

void UnsortedTypeArray::MakeEmpty() { length = 0; }
void UnsortedTypeArray::ResetList() { currentPos = -1; }

ItemType UnsortedTypeArray::GetItem(ItemType& item, bool& found) {
    // Pre: Key member(s) of item is initialized
    // Post: if found, item's key matches elem key in
    //      list and a copy of that elem has been returned
    //      otherwise, item is returned
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
        case GREATER:
            location++;
            moreToSearch = (location < length);
            break;
        case EQUAL:
            found = true;
            item = info[location];
            break;
        }
    }
    return item;
}
void UnsortedTypeArray::PutItem(ItemType item) {
    // Post: item is in the list
    info[length] = item;
    length++;
}

void UnsortedTypeArray::DeleteItem(ItemType item) {
    // Pre: item's key initialized
    // an elem in list has a key that matches item's
    // post: no elem in the list has a key that matches

    int validPointer = 0;
    for (int i = 0; i < length; i++) {
        // use Two pointers and keep track of last invalidIdx we can replace
        if (info[i].GetValue() != item.GetValue()) {
            info[validPointer] = info[i];
            validPointer++;
            length--;
        }
    }
}

ItemType UnsortedTypeArray::GetNextItem() {
    currentPos++;
    return info[currentPos];
}

void UnsortedTypeArray::ShiftRight() {
    if (length == 0) {
        cout << "Empty." << endl;
        return;
    } else {
        // grab end of arr
        ItemType newStart = info[length - 1];
        ItemType front = newStart;
        // initialize temp
        ItemType temp;

        for (int i = 0; i < length; i++) {
            temp = info[i];
            info[i] = front;
            front = temp;
        }
    }
}

void UnsortedTypeArray::Print() {
    if (length == 0) {
        cout << "Empty." << endl;
        return;
    }
    currentPos = 0;
    while (currentPos < length) {
        info[currentPos].Print(cout);
        currentPos++;
    }
}
