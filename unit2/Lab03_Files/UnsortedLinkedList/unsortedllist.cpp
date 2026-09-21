// This file contains the linked implementation of class
// UnsortedType.

#include "unsortedllist.h"
#include <iostream>
using namespace std;
struct NodeType {
    ItemType info;
    NodeType* next;
};

UnsortedTypeLinkedList::UnsortedTypeLinkedList() // Class constructor
{
    length = 0;
    listData = NULL;
}
bool UnsortedTypeLinkedList::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

int UnsortedTypeLinkedList::GetLength() const
// Post: Number of items in the list is returned.
{
    return length;
}

void UnsortedTypeLinkedList::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
void UnsortedTypeLinkedList::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType* location; // Declare a pointer to a node

    location = new NodeType;   // Get a new node
    location->info = item;     // Store the item in the node
    location->next = listData; // Store address of first node
                               //   in next field of new node
    listData = location;       // Store address of new node into
                               //   external pointer
    length++;                  // Increment length of the list
}

ItemType UnsortedTypeLinkedList::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info)) {
        case LESS:
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}

void UnsortedTypeLinkedList::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType* location = listData;
    NodeType* tempLocation;

    // Locate node to be deleted.
    if (item.ComparedTo(listData->info) == EQUAL) {
        tempLocation = location;
        listData = listData->next; // Delete first node.
    } else {
        while (item.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void UnsortedTypeLinkedList::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}

ItemType UnsortedTypeLinkedList::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
    return item;
}

UnsortedTypeLinkedList::~UnsortedTypeLinkedList()
// Post: List is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedTypeLinkedList::Print() {
    if (length == 0) {
        cout << "Empty." << endl;
        return;
    }
    currentPos = listData;
    while (currentPos != NULL) {
        currentPos->info.Print();
        currentPos = currentPos->next;
    }
}
void UnsortedTypeLinkedList::ShiftRight() {
    // ResetList();
    NodeType* newList = listData;
    if (listData == nullptr) {
        cout << "Empty." << endl;
        return;
    } else {
        // find the last node
        while (newList->next != nullptr) {
            newList = newList->next;
        };

        NodeType* front = listData;
        listData = newList; // start off the new list
        NodeType* temp = newList;
        for (int i = 0; i < length; i++) {
            temp->next = front;
            temp = front;
            front = front->next;
        }
        front->next->next = nullptr;
    }
}

void UnsortedTypeLinkedList::SplitLists(UnsortedTypeLinkedList& list,
                                        ItemType item,
                                        UnsortedTypeLinkedList& list1,
                                        UnsortedTypeLinkedList& list2) {
    if (length == 0)
        return;
    currentPos = listData;
    while (currentPos != NULL) {
        ItemType compItem = currentPos->info;
        if (compItem.ComparedTo(item) <= 1) {

            list1.PutItem(compItem);
        } else {

            list2.PutItem(compItem);
        }
        currentPos = currentPos->next;
    }
}
