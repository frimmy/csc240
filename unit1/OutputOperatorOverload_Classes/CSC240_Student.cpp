//============================================================================
// Name        : CSC240_Student.cpp
// Author      : Ivan Temesvari
// Date        : 1/26/2022
//============================================================================

#include <iostream>
#include "StudentType.h"
using namespace std;

int main() {
	StudentType student1;
	DateType student1Birthday;
	student1Birthday.Initialize(5, 1, 2005);
	student1.Initialize("Ivan", student1Birthday, MARRIED);
	cout << student1 << endl;
	student1.print();
	return 0;
}
