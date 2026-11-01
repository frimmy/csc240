// Creative Final Feature: Iterative TreeType::AncestorsIterative --
// (see TreeDrIterative.cpp)
// What does your feature do? Returns the ancestors using iterative approach
// instead of recursion.

// What concept from your AI Learning Query did it use?
// Two pass iteration -- where the first pass is used to determine whether
// there's a node that exists that matches the item being searched for before
// beginning to build the ancestor path. This reduces the run time for string
// comp from O(h^2) in the recursive approach down to O(n) with the iterative
// approach for the worst case of a sorted input.

// What did you try that did not work?
// While it "worked", my first iterative approach used a single pass and built
// the string during the loops whether the string existed or not -- which wasn't
// optimal in worst cases where we had a deeply nested tree without a matching
// node. W/ two pass - we first verify a node exists before building the
// ancestor path.

// What would you do next if you had another week?
// Include a stack profile of the difference between iterative vs. recursive
// between the space/time complexity.

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
    cout << tree.Ancestors("T") << endl;

    cout << "Call on root (J):" << endl;
    cout << tree.Ancestors("J") << endl;

    cout << "search for nodes don't exist - Q: " << endl;
    cout << tree.Ancestors("Q") << endl;
    cout << "search for nodes don't exist - Z: " << endl;
    cout << tree.Ancestors("Z") << endl;

    cout << "search for deep leaves: Y" << endl;
    cout << tree.Ancestors("Y") << endl;
    cout << "search for deep leaves: F" << endl;
    cout << tree.Ancestors("F") << endl;

    TreeType<string> emptyTree;
    cout << "search empty tree" << endl;
    cout << emptyTree.Ancestors("A") << endl;
    return 0;
}
