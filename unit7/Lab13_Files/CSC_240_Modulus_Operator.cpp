/*============================================================================
// Name        : CSC_240_Modulus_Operator.cpp
// Author      : Ivan Temesvari

Observe the following modulus operation: -12 % 7.

If we perform this in C++11 (or later), we get -5.

Typically (most other programming languages and many mathematical contexts), we would expect a positive result, but clearly it is not.

In most cases we have, -12 % 7 = 2.

In C++, we can get this using the remainder function like so: remainder(-12, 7) = 2.

The way C++ performs the operation using % is as such:

remainder = a - b * truncate(a / b)

This technique of finding the remainder of a / b uses the fact that C++ always "rounds towards zero" (i.e., uses truncation) when performing integer division.

So, in this example we have:

-12 % 7 = -12 - 7 * truncate(-12 / 7) = -12 - 7 * -1 = -12 + 7 = -5

It is also worth noting that -5 ≡ 2 (modulo 7). So, C++ isn't wrong, it's just strange :)
============================================================================*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << -12 % 7 << endl;
	cout << remainder(-12, 7) << endl;
	return 0;
}
