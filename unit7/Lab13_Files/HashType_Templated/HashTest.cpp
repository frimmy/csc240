/*
 * HashTest.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: Ivan Temesvari
 */
#include "HashType.h"
#include <cmath>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	HashType<string> myHashTableDivision(11);
	myHashTableDivision.Insert("at");
	myHashTableDivision.Insert("ta");
	myHashTableDivision.Insert("the");
	myHashTableDivision.Insert("college");
	myHashTableDivision.Insert("house");
	myHashTableDivision.Insert("paper");
	myHashTableDivision.Insert("toy");
	myHashTableDivision.Insert("business");
	myHashTableDivision.Insert("work");


	cout << myHashTableDivision;
	cout << "Number of collisions: " << myHashTableDivision.GetCollisions() << endl << endl;
}



