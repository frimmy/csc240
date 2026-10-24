//============================================================================
// Name        : Ivan Temesvari
// Author      : 3/21/2022
// Practice with recursive functions.
//============================================================================

#include <iostream>
using namespace std;


template <class ItemType> struct NodeType
{
  ItemType info;
  NodeType<ItemType>* next;
};

//Print a linked list in reverse order.
template <class ItemType>
void RevPrint(NodeType<ItemType>* listPtr)
{
  if (listPtr != NULL)
  {
    RevPrint(listPtr->next);
    cout << listPtr->info;
  }
}

//Print a linked list in order.
template <class ItemType>
void Print(NodeType<ItemType>* listPtr)
{
  if (listPtr != NULL)
  {
	  cout << listPtr->info;
	  Print(listPtr->next);
  }
}

int LinearFactorial(int number){
	int product = 1;
	for(int i = number; i >= 1; i--){
		product *= i;
	}
	return product;
}

int Factorial(int number)
// Pre: number is nonnegative.
// Post: Function value = factorial of number.
{
  if (number == 1) // line 1
    return 1;    // line 2
  else
    return number * Factorial(number-1); // line 3
}

int main() {
	cout << Factorial(6) << endl;
	cout << LinearFactorial(6) << endl;

	string myName = "Ivan";
	NodeType<char>* name;
	//Build the list.
	NodeType<char>* firstNode = NULL;
	for(auto c: myName){
		NodeType<char>* newNode = new NodeType<char>;
		if(firstNode == NULL){ //first node
			newNode->info = c;
			newNode->next = NULL;
			name = newNode;
		}
		else{
			newNode->info = c;
			newNode->next = firstNode->next;
			firstNode->next = newNode;
		}
		firstNode = newNode;
	}
	RevPrint(name);
	cout << endl;
	Print(name);

	return 0;
}
