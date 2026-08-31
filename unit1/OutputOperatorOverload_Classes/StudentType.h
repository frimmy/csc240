#ifndef STUDENT_H
#define STUDENT_H
#include "PersonType.h"
#include <string>
#include <iostream>
using namespace std;
enum StatusType {SINGLE, MARRIED, WIDOWED};
class StudentType : public PersonType
{
public:
  StatusType GetStatus() const;
  void   Initialize(string, DateType, StatusType);
  void print();
  friend ostream& operator<<(ostream&, const StudentType&);
  string GetStatusAsString() const;
private:
  StatusType status;
};

// Names of the statuses
static string conversionTableStatus[] = {"Single", "Married", "Widowed"};

string StudentType::GetStatusAsString() const
{
  return conversionTableStatus[status];
}

void StudentType::print(){
	PersonType::print();
	cout << GetStatusAsString() << endl;
}

ostream& operator<<(ostream& out, const StudentType& s){
	out << static_cast<const PersonType&>(s);
	out << s.GetStatusAsString() << endl;
	return out;
}

void StudentType::Initialize(string newName, DateType newBirthdate,	StatusType newStatus)
{
  status = newStatus;
  PersonType::Initialize(newName, newBirthdate);
}

StatusType StudentType::GetStatus() const
{
  return status;
}
#endif
