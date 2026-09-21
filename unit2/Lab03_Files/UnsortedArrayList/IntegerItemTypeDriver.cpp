/*
 * itemTypeDriver.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: igt88
 */
#include "unsortedalist.h"
#include <iostream>
using namespace std;

int main() {
    ItemType item1, item2, item3;

    item1.Initialize(1);
    item2.Initialize(3);
    item3.Initialize(5);

    UnsortedTypeArray integerList;

    integerList.PutItem(item1);
    integerList.PutItem(item2);

    cout << "Compare item1 to item1: " << item1.ComparedTo(item1)
         << endl; // expect 1 for same status
    cout << "Compare item1 to item2: " << item1.ComparedTo(item2)
         << endl; // expect 0 when status is not the same

    cout << "Print list 0:\n";
    integerList.ResetList(); // reset the current position to NULL
    integerList.Print();
    cout << "Print list 1:\n";
    integerList.DeleteItem(item1);
    integerList
        .ResetList(); // this must be reset before printing the list everytime
    integerList.Print();
    cout << "Print list 2:\n";
    integerList.PutItem(item3);
    integerList
        .ResetList(); // this must be reset before printing the list everytime
    integerList.Print();
    cout << "Print list 3:\n";
    integerList.DeleteItem(item2);
    integerList.DeleteItem(item3);
    integerList.ResetList();
    integerList.Print();
    return 0;
}
