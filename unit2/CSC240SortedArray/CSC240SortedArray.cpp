//============================================================================
// Name        : CSC240SortedArray.cpp
// Author      : Adrian Frimpong
// Date        : 9/13/2026
//============================================================================

// What does your feature do? Tracks number of reallocations performed
// What concept from your AI Learning Query did it use?
// the use of the 1.5 ratio to take advantage of smarter graveyard reuse
// What did you try that did not work?
// n/a -- was fairly straightfwd!
// What would you do next if you had another week
// implement the shrinking part of the resize

#include "sorted.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    SortedType myList;
    cout << myList.GetMaxLength() << endl;
    ++myList; // unary operator, pre-increment operator++. The size of the list
              // is increased by 1.
    myList++; // unary operator, post-increment operator++. The size of the list
              // is increased by 1.
    cout << myList.GetMaxLength() << endl;

    for (int i = 0; i < 1000; i++) {
        ItemType item;
        item.Initialize(rand() % 100 + 1);
        myList.PutItem(item);
    }

    cout << "myList capacity: " << myList.GetMaxLength() << endl;
    cout << "myList allocations: " << myList.GetAllocations() << endl;

    return 0;
}
