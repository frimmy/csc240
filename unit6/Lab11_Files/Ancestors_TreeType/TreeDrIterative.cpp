// Write a recursive TreeType member function called Ancestors that returns a
// string representing the ancestors (in reverse order) of a particular node
// whose info member contains value. Use the following signature: string
// TreeType<ItemType>::Ancestors(ItemType item) const NOTE the trailing const -
// it is part of the declaration in TreeType.h, and leaving it off will not
// match. Ivan Temesvari 3/11/2019

#include "TreeType.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    TreeType<string> tree;

    tree.PutItem("J");
    tree.PutItem("D");
    tree.PutItem("A");
    tree.PutItem("B");
    tree.PutItem("G");
    tree.PutItem("E");
    tree.PutItem("H");
    tree.PutItem("F");
    tree.PutItem("P");
    tree.PutItem("K");
    tree.PutItem("L");
    tree.PutItem("U");
    tree.PutItem("S");
    tree.PutItem("T");
    tree.PutItem("W");
    tree.PutItem("X");
    tree.PutItem("Y");

    cout << "Search for T: J->P->U->S" << endl;
    cout << tree.AncestorsIterative("T") << endl;

    cout << "Call on root (J):" << endl;
    cout << tree.AncestorsIterative("J") << endl;

    cout << "search for nodes don't exist - Q: " << endl;
    cout << tree.AncestorsIterative("Q") << endl;
    cout << "search for nodes don't exist - Z: " << endl;
    cout << tree.AncestorsIterative("Z") << endl;

    cout << "search for deep leaves: Y" << endl;
    cout << tree.AncestorsIterative("Y") << endl;
    cout << "search for deep leaves: F" << endl;
    cout << tree.AncestorsIterative("F") << endl;

    TreeType<string> emptyTree;
    cout << "search empty tree" << endl;
    cout << emptyTree.AncestorsIterative("A") << endl;
    return 0;
}
