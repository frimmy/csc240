/*
Ch. 3 - Linked Lists
- structures made up of nodes that contain list items
- Singly-linked lists can implement Stack and FIFO Queue operations
- Double-linked lists can implement Dequeue in constant time

Advgs/Disadvgs compared to array-based implementation of ListInterface

Primary Disatvgs:
- lose ability to access any elem using get(i)/set(i,x) in constant time
- We have to walk thru the list one elem at a time

Primary Advg:
- Given a ref to any list node u, can delete u/insert a node adjacent in
constant time!
*/

// 3.1 - SLList - Singly-Linked List
// * sequence of `Nodes`
// Each node u stores a data value - u.x
// and a ref to u.next to next node in sequence
// For last node, w.next = null

#include <cstddef>
using namespace std;

template <typename T> class Node {
  public:
    T x;
    Node* next;
    Node(T x0) {
        x = 0;
        next = nullptr_t;
    }
};
template <typename T> class SLList {

    // Efficiency -- SLList uses variables `head` | `tail` to track
    // 1st / last node in sequence and `n` to track length
  public:
    Node<T>* head;
    Node<T>* tail;

    // implement Stack ops, push(), pop() adding / removing elems
    // at head of sequence.
    // Push() just creats a new node with, sets u.next to old head of list
    // and makes u new head of list.
    // + increments `n` since size of SLList increased
    T push(T x) {
        Node* u = new Node(x);
        u->next = head;
        head = u;
        if (n == 0)
            tail = u;
        n++;
        return x;
    }

    T pop() {
        if (n == 0)
            return null;
        T x = head->x; // arrow operator == pointer dereference
        Node* u = head;
        head = head->next;
        delete u;
        if (--n == 0)
            tail = nullptr_t;
        return x;
    }
    // push/pop ops == O(1) time.

    // 3.1.1 Queue operations
    // can add add(x) and remove() FIFO queue operations
    // from head of list. Removals identical to pop()
    T remove() {
        if (n == 0)
            return null;
        T x = head->x; // arrow operator == pointer dereference
        Node* u = head;
        head = head->next;
        delete u;
        if (--n == 0)
            tail = nullptr_t;
        return x;
    }
    // additions are done from tail tho!
    // setting tail.next = u, where u = new Node
    // special case: when n = 0;
    // - tail = head = null
    // - both tail'n head are set to u!
    bool add(T x) {
        Node* u = new Node(x);
        if (n == 0)
            head = u;
        else
            tail->next = u; // asign tail's next pointer ref to new Node!
        tail = u;           // reassign the pointer to point to new Node!
        n++;
        return true;
    }

    // again - add(x), remove ops are O(1), or constant time
};

// Summary - SLLIst implements Stack, and FIFO Queue interfaces
// push, pop, add(x) and remove() are O(1)

// also implements full set of Dequeue operations
// except remove from tail of SLList
// challenging because it requires updates value of tail so that it points
// to node w preceding tail;
// this is node `w` such that w.next = tail
// Only way to do THAT - traverse SLList starting at head -
// taking n - 2 steps!
