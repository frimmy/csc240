/*
 * StudentTypeDriver.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: igt88
 */
#include "unsortedllist.h"
#include <iostream>
using namespace std;

int testmain() {
    cout << "**** Splitting ****" << endl;
    StudentType student1, student2, student3;
    DateType student1DOB, student2DOB, student3DOB;

    student1DOB.Initialize(7, 15, 1978);
    student2DOB.Initialize(6, 23, 1980);
    student3DOB.Initialize(3, 4, 1945);

    student1.Initialize("Ivan", student1DOB, ENROLLED);
    student2.Initialize("Jim", student2DOB, GRADUATED);
    student3.Initialize("Billy", student3DOB, NON_ATTENDING);

    UnsortedTypeLinkedList classList1;
    UnsortedTypeLinkedList classList2;
    UnsortedTypeLinkedList classList3;

    classList1.PutItem(student1);
    classList1.PutItem(student2);
    classList1.PutItem(student3);
    classList1.SplitLists(classList1, student1, classList2, classList3);

    cout << "list2" << endl;
    classList2.ResetList();
    classList2.Print();
    cout << "list3" << endl;
    classList3.ResetList();
    classList3.Print();

    return 0;
}
