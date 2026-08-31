// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "frac.h"
int main()
{

	FractionType one;
	FractionType two;
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	FractionType three = one + two;
	three.print();  //Implement this function
	cout << three << endl; //Implement this function

	FractionType x;
	FractionType y;
	x.Initialize(1, 3);
	y.Initialize(2, 3);
	FractionType z = x + y;
	z.print();
	cout << z << endl;
	
	//Test the other overloaded operators: operator-, operator*, operator/ here.


	//Extra Credit +2: reduce*********************
	z.reduce();
	z.print();
	cout << z << endl;

	FractionType g;
	g.Initialize(15, 20);
	g.reduce();
	g.print();
	cout << g << endl;
	//********************************************
	
	
}
