// Implementation file for class FractionType
#include "frac.h"
#include <iostream>

void FractionType::Initialize(int numerator, int denominator)
// Function: Initialize the fraction
// Pre:  None
// Post: numerator is stored in num; denominator is stored in
//       denom
{
    num = numerator;
    denom = denominator;
}
int FractionType::NumeratorIs()
// Function: Returns the value of the numerator
// Pre:  Fraction has been initialized
// Post: numerator is returned
{
    return num;
}
int FractionType::DenominatorIs()
// Function: Returns the value of the denominator
// Pre:  Reaction has been initialized
// Post: denominator is returned
{
    return denom;
}

bool FractionType::IsZero()
// Function: Determines if fraction is zero
// Pre:  Fraction has been initialized
// Post: Returns true if numerator is zero
{
    return (num == 0);
}

bool FractionType::IsNotProper()
// Function: Determines if fraction is a proper fraction
// Pre:  Fraction has been initialized
// Post: Returns true if num is greater than or equal to denom
{
    return (abs(num) >= abs(denom));
}

int FractionType::ConvertToProper()
// Function: Converts the fraction to a whole number and a
//       fractional part
// Pre:  Fraction has been initialized, is in reduced form, and
//       is not a proper fraction
// Post: Returns num divided by denom
//       num is original num % denom; denom is not changed
{
    int result;
    result = num / denom;
    num = num % denom;
    return result;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void FractionType::reduce()
// Function: Converts the fraction to its lowest terms
// Pre: Fraction has been initialized.
// Post: fraction is in reduced form
{
    // initialize a/b
    int commonDenom = gcd(num, denom);
    if (denom != commonDenom) {
        denom /= commonDenom;
        num /= commonDenom;
    }

    if (denom < 0 && num >= 0) {
        num = -num;
        denom = -denom;
    }
}

void FractionType::print(ostream& out)
// Function: Print the fraction to screen
// Pre:  Fraction has been initialized, is in reduced form, and
//       is a proper fraction
// Post: Fraction is printed to screen
{
    reduce();
    string numerator = to_string(num);
    string denominator = to_string(denom);
    out << numerator << "/" << denominator << endl;
}

FractionType operator+(FractionType& a, FractionType& b)
// Function: Adds fractions
// Pre:  Fractions have been initialized
// Post: Returns the sum of both sides of operator
{
    int commonDenominator = a.DenominatorIs() * b.DenominatorIs();
    int newNumerator = b.DenominatorIs() * a.NumeratorIs() +
                       a.DenominatorIs() * b.NumeratorIs();

    FractionType sum;
    sum.Initialize(newNumerator, commonDenominator);
    return sum;
}
FractionType operator-(FractionType& a, FractionType& b)
// Function: subtracts fractions
// Pre:  Fractions have been initialized
// Post: Returns the sum of both sides of operator
{

    int commonDenominator = a.DenominatorIs() * b.DenominatorIs();
    int newNumerator = b.DenominatorIs() * a.NumeratorIs() -
                       a.DenominatorIs() * b.NumeratorIs();

    FractionType difference;
    difference.Initialize(newNumerator, commonDenominator);
    return difference;
}
FractionType operator*(FractionType& a, FractionType& b)
// Function: multiplies fractions
// Pre:  Fractions have been initialized
// Post: Returns the product of both sides of operator
{

    FractionType product;
    product.Initialize(a.NumeratorIs() * b.NumeratorIs(),
                       a.DenominatorIs() * b.DenominatorIs());
    return product;
}
FractionType operator/(FractionType& a, FractionType& b)
// Function: divides fractions
// Pre:  Fractions have been initialized
// Post: Returns the division of both sides of operator
{

    FractionType quotient;
    quotient.Initialize(a.NumeratorIs() * b.DenominatorIs(),
                        a.DenominatorIs() * b.NumeratorIs());
    return quotient;
}

ostream& operator<<(ostream& out, FractionType& f)
// Function: Chains output of fraction to ostream object
// Pre:  Fraction has been initialized, is in reduced form, and
//       is a proper fraction
// Post: Fraction is output to ostream object, ostream is returned.
{
    f.print(out);
    return out;
}
