//============================================================================
// Name        : CSC240_CompareIntString.cpp
// Author      : Ivan Temesvari
// Version     :
// Copyright   : 5/6/2019
// Description : Compare Ints to Strings
//============================================================================

#include <iostream>
#include <string>
using namespace std;

bool CompareStringToInt(int x, string s){
	string integer_as_string = std::to_string(x);  //int to string
	//int string_as_integer = std::atoi(s.c_str());  //string to int
	if(s == integer_as_string)
		return true;
	else
		return false;
}

bool CompareIntWithInfinity(int x){
	string integer_as_string = std::to_string(x);
	if(integer_as_string == "-")
		return true;
	else
		return false;
}

int main() {
	string text = "-";
	cout << text << endl;
	cout << std::to_string(45) << endl;
	bool comp1 = CompareStringToInt(45, "-");
	cout << "Are they equal? " << comp1 << endl;
	bool comp2 = CompareIntWithInfinity(45);
	cout << "Are they equal? " << comp2 << endl;
	return 0;
}
