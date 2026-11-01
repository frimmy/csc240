#ifndef TREETYPE_H
#define TREETYPE_H
#include "QueType.h"
#include <fstream>
#include <string>
using namespace std;

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

template <class ItemType> struct TreeNode;

template <class ItemType> class TreeType {
  public:
    TreeType();  // constructor
    ~TreeType(); // destructor
    TreeType(const TreeType<ItemType>& originalTree);
    void operator=(const TreeType<ItemType>& originalTree);
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
    void Print(ofstream& outFile) const;
    string Ancestors(ItemType item) const;
    string AncestorsIterative(ItemType item) const;

  private:
    string AncestorsNext(TreeNode<ItemType>* node, ItemType item) const;
    TreeNode<ItemType>* root;
    QueType<ItemType> preQue;
    QueType<ItemType> inQue;
    QueType<ItemType> postQue;
};

template <class ItemType> struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template <class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns true if there is no room for another item
//  on the free store; false otherwise.
{
    TreeNode<ItemType>* location;
    try {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
    return root == NULL;
}

template <class ItemType> int CountNodes(TreeNode<ItemType>* tree);

template <class ItemType>
int TreeType<ItemType>::GetLength() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
    return CountNodes(root);
}

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
    if (tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);

template <class ItemType>
ItemType TreeType<ItemType>::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
    Retrieve(root, item, found);
    return item;
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise found is false and item is unchanged.
{
    if (tree == NULL)
        found = false; // item is not found.
    else if (item < tree->info)
        Retrieve(tree->left, item, found); // Search left subtree.
    else if (item > tree->info)
        Retrieve(tree->right, item, found); // Search right subtree.
    else {
        item = tree->info; // item is found.
        found = true;
    }
}

template <class ItemType> void Insert(TreeNode<ItemType>*& tree, ItemType item);

template <class ItemType>
void TreeType<ItemType>::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
    Insert(root, item);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
    if (tree == NULL) { // Insertion place found.
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if (item < tree->info)
        Insert(tree->left, item); // Insert in left subtree.
    else
        Insert(tree->right, item); // Insert in right subtree.
}

template <class ItemType> void DeleteNode(TreeNode<ItemType>*& tree);

template <class ItemType> void Delete(TreeNode<ItemType>*& tree, ItemType item);

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
    Delete(root, item);
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
    if (item < tree->info)
        Delete(tree->left, item); // Look in left subtree.
    else if (item > tree->info)
        Delete(tree->right, item); // Look in right subtree.
    else
        DeleteNode(tree); // Node found; call DeleteNode.
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
    ItemType data;
    TreeNode<ItemType>* tempPtr;

    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data); // Delete predecessor node.
    }
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

template <class ItemType>
void PrintTree(TreeNode<ItemType>* tree, ofstream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
    if (tree != NULL) {
        PrintTree(tree->left, outFile); // Print left subtree.
        outFile << tree->info;
        PrintTree(tree->right, outFile); // Print right subtree.
    }
}

template <class ItemType>
void TreeType<ItemType>::Print(ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
    PrintTree(root, outFile);
}

template <class ItemType> TreeType<ItemType>::TreeType() { root = NULL; }

template <class ItemType> void Destroy(TreeNode<ItemType>*& tree);

template <class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
    Destroy(root);
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

template <class ItemType> void TreeType<ItemType>::MakeEmpty() {
    Destroy(root);
    root = NULL;
}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
              const TreeNode<ItemType>* originalTree);

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy originalTree
//  into root.
{
    CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType<ItemType>::operator=(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
// into root.
{
    {
        if (&originalTree == this)
            return;    // Ignore assigning self to self
        Destroy(root); // Deallocate existing tree nodes
        CopyTree(root, originalTree.root);
    }
}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree)
// Post: copy is the root of a tree that is a duplicate
//       of originalTree.
{
    if (originalTree == NULL)
        copy = NULL;
    else {
        copy = new TreeNode<ItemType>;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

// Function prototypes for auxiliary functions.
template <class ItemType>
void PreOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in preorder.

template <class ItemType> void InOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in inorder.

template <class ItemType>
void PostOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in postorder.

template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in
// the desired order.
{
    switch (order) {
    case PRE_ORDER:
        PreOrder(root, preQue);
        break;
    case IN_ORDER:
        InOrder(root, inQue);
        break;
    case POST_ORDER:
        PostOrder(root, postQue);
        break;
    }
}

template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>& preQue)
// Post: preQue contains the tree items in preorder.
{
    if (tree != NULL) {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}

template <class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType<ItemType>& inQue)
// Post: inQue contains the tree items in inorder.
{
    if (tree != NULL) {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}

template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>& postQue)
// Post: postQue contains the tree items in postorder.
{
    if (tree != NULL) {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree->info);
    }
}

template <class ItemType>
ItemType TreeType<ItemType>::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true;
//       otherwise finished is false.
{
    finished = false;
    ItemType item;
    switch (order) {
    case PRE_ORDER:
        preQue.Dequeue(item);
        if (preQue.IsEmpty())
            finished = true;
        break;
    case IN_ORDER:
        inQue.Dequeue(item);
        if (inQue.IsEmpty())
            finished = true;
        break;
    case POST_ORDER:
        postQue.Dequeue(item);
        if (postQue.IsEmpty())
            finished = true;
        break;
    }
    return item;
}

// This iterative function will return the ancestors of item in reverse order
// relative to the node with the searched item, root first, immediate parent
// last
// Pre: the ItemType is of "string" type
// Post: returns the ancestor path of node with item, "empty tree" if the tree
// is empty, "root node" if the root has the item, or "not found" if item is not
// in tree
template <class ItemType>
string TreeType<ItemType>::AncestorsIterative(ItemType item) const {
    // empty tree
    if (root == NULL) {
        return "empty tree";
    }
    // item is found and is root
    if (root->info == item) {
        return "root node";
    }
    TreeNode<ItemType>* currentNode = root;
    // build ancestor path iteratively while we've not found match
    // Use Two-pass traversal and only run string concat if the item is in the
    // tree
    while (currentNode != NULL && currentNode->info != item) {
        if (item < currentNode->info) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    // check if we've reached NULL / not found case
    if (currentNode == NULL) {
        return "not found";
    } else {
        // reset current to root for 2nd pass
        currentNode = root;
    }

    // proceed with string building path
    string ancestorsString = "";
    // build ancestor path iteratively while we've not found match
    while (currentNode->info != item) {
        if (ancestorsString == "") {
            ancestorsString = currentNode->info;
        } else {
            ancestorsString += " ";
            ancestorsString += currentNode->info;
        }
        if (item < currentNode->info) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return ancestorsString;
}
// Adrian Frimpong
// 10/31/2026
// This recursive function will return the ancestors of item in reverse order
// relative to the node with the searched item, root first, immediate parent
// last
// NOTE: just works with ItemType == string
// Pre: the ItemType is of "string" type
// Post: returns the ancestor path of node with item, "empty tree" if the tree
// is empty, "root node" if the root has the item, or "not found" if item is not
// in tree
template <class ItemType>
string TreeType<ItemType>::Ancestors(ItemType item) const {
    // empty tree
    if (root == NULL) {
        return "empty tree";
    }
    // item is found and is root
    if (root->info == item) {
        return "root node";
    }
    return AncestorsNext(root, item);
}

// Recursively builds ancestors for item in subtree.
// Post: Returns ancestor path for an item whose key matches item, otherwise
// returns "not found"
// Invariant: returns "" in case we've arrived at the node
// that holds the item, or returns the search path from the current node as far
// as but not including the node with item, or returns "not found" if the item
// is not in the subtree
template <class ItemType>
string TreeType<ItemType>::AncestorsNext(TreeNode<ItemType>* node,
                                         ItemType item) const {
    string ancestorsString;
    // Base cases:
    // node is null
    if (node == NULL) {
        return "not found";
    }
    // item is found
    if (node->info == item) {
        return "";
    }
    if (item < node->info) {
        ancestorsString = AncestorsNext(node->left, item);
    } else {
        ancestorsString = AncestorsNext(node->right, item);
    }

    if (ancestorsString == "not found") {
        return "not found";
    }

    return ancestorsString == "" ? node->info
                                 : node->info + " " + ancestorsString;
}
#endif
