#ifndef TREE_H
#define TREE_H
#include <string>
#include <fstream>
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print(std::ostream& outStream) const;
  void checkSizes(std::ostream& outStream) const;
  void PrintOrder(OrderType order);
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};
#endif
