#include <ostream>
#ifndef FRACTION_TYPE
#define FRACTION_TYPE

using namespace std;

class FractionType {
  public:
    void Initialize(int numerator, int denominator);
    // Function: Initialize the fraction
    // Pre:  None
    // Post: Fraction is initialized
    int NumeratorIs();
    // Function: Returns the value of the numerator
    // Pre:  Fraction has been initialized
    // Post: numerator is returned
    int DenominatorIs();
    // Function: Returns the value of the denominator
    // Pre:  Reaction has been initialized
    // Post: denominator is returned
    bool IsZero();
    // Function: Determines if fraction is zero
    // Pre:  Fraction has been initialized
    // Post: Returns true if numerator is zero
    bool IsNotProper();
    // Function: Determines if fraction is a proper fraction
    // Pre:  Fraction has been initialized
    // Post: Returns true if fraction is greater than one
    int ConvertToProper();
    // Function: Converts the fraction to a whole number and a
    //       fractional part
    // Pre:  Fraction has been initialized, is in reduced form, and
    //       is not a proper fraction
    // Post: Returns whole number
    //       Remaining fraction is original fraction minus the
    //       whole number; fraction is in reduced form
    void print(ostream& out);
    // Function: Print the fraction to screen
    // Pre:  Fraction has been initialized, is in reduced form, and
    //       is a proper fraction
    // Post: Fraction is printed to screen
    friend FractionType operator+(FractionType&, FractionType&);
    // Function: Adds fractions
    // Pre:  Fractions have been initialized
    // Post: Returns the sum of both sides of operator
    friend FractionType operator-(FractionType&, FractionType&);
    // Function: Adds fractions
    // Pre:  Fractions have been initialized
    // Post: Returns the difference of both sides of operator
    friend FractionType operator*(FractionType&, FractionType&);
    // Function: Adds fractions
    // Pre:  Fractions have been initialized
    // Post: Returns the product of both sides of operator
    friend FractionType operator/(FractionType&, FractionType&);
    // Function: Adds fractions
    // Pre:  Fractions have been initialized
    // Post: Returns the division of both sides of operator

    void reduce();
    // Function: Converts the fraction to its lowest terms
    // Pre: Fraction has been initialized.
    // Post: fraction is in reduced form

  private:
    int num;
    int denom;
};

ostream& operator<<(ostream&, FractionType&);
// Function: Chains output of fraction to ostream object
// Pre:  Fraction has been initialized, is in reduced form, and
//       is a proper fraction
// Post: Fraction is output to ostream object, ostream is returned.
#endif
