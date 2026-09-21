#ifndef ITEMTYPE_H
#define ITEMTYPE_H
// The following declarations and definitions go into file
// ItemType.h.
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;
enum RelationType { LESS, EQUAL, GREATER };

class ItemType {
  public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(ostream&) const;
    void Initialize(int number);
    int GetValue();

  private:
    int value;
};

inline int ItemType::GetValue() { return value; }

inline ItemType::ItemType() { value = 0; }

inline RelationType ItemType::ComparedTo(ItemType otherItem) const {
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

inline void ItemType::Initialize(int number) { value = number; }

inline void ItemType::Print(ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    out << value << endl;
}
#endif
