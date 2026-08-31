#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "DateType.h"
#include <iostream>
using namespace std;
class PersonType
{
public:
  void Initialize(string, DateType);
  string NameIs();
  DateType BirthdateIs();
  void print();
  friend ostream& operator<<(ostream&, const PersonType&);
private:
  string name;
  DateType birthdate;
};

void PersonType::print(){
	cout << name << "\n" << birthdate << endl;
}

ostream& operator<<(ostream& out, const PersonType& p){
	out << p.name << "\n" << p.birthdate << endl;
	return out;
}

void PersonType::Initialize(string s, DateType d){
	name = s;
	birthdate = d;
}

//Accessor for the name of the PersonType object
string PersonType::NameIs(){
	return name;
}

//Accessor for the birthdate of the PersonType object
DateType PersonType::BirthdateIs(){
	return birthdate;
}

#endif
