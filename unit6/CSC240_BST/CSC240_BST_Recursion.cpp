//============================================================================
// Name        : Ivan Temesvari
// Description : BST and Recursion
// Date        : 3/30/2022
//============================================================================

#include <iostream>
#include "TreeType.h"
using namespace std;

int main() {
	TreeType myTree;
	myTree.PutItem('K');
	myTree.PutItem('G');
	myTree.PutItem('Q');
	myTree.PutItem('D');
	myTree.PutItem('J');
	myTree.PutItem('P');
	myTree.PutItem('S');
	myTree.PutItem('C');
	myTree.PutItem('H');
	myTree.PutItem('R');


	myTree.ResetTree(PRE_ORDER);
	myTree.PrintOrder(PRE_ORDER);
	myTree.ResetTree(IN_ORDER);
	myTree.PrintOrder(IN_ORDER);
	myTree.ResetTree(POST_ORDER);
	myTree.PrintOrder(POST_ORDER);


	myTree.checkSizes(cout);
	return 0;
}
