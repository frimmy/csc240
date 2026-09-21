/*
3.2 - DLList - Doubly-Linked List
similar to SLList but each node u in a DLList
has references to both u.next AND u.prev (preceding it)
*/

//'Member those special cases from SLLists?
// DLLists got a lot more of those.
// e.g. in DLList, need to care to adding/removing
// to ensure head/tail are kept up to date.
// CLEANEST WAY? Make a `dummy` node -- doesn't contain
// data- but is a placeholder so there aren't special nodes.
// EVERY node has next/prev
// - dummy acts as the node following LAST node and
//   the one precedes the FIRST node💡
// In this way - the nodes are linked in a CYCLE (see notebook notes for
// drawing)
template <typename T> struct Node {
    T x;
    Node *prev, *next;
};

template <typename T> class DLList {
  public:
    Node<T> dummy;
    int n;
    DLList() {
        dummy.next = &dummy;
        dummy.prev = &dummy;
        n = 0;
    }
    // Finding node w/ particlar index in DLList EASY!
    // - start at head (dummy.next) and work fwd
    // or ..start at tail (dummy.prev) and work backwd.
    // allows us to reach ith node in O(1+min{i, n -1}) time

    Node<T>* getNode(int i) {
        Node<T>* p;
        if (i < n / 2) {
            p = dummy.next;
            for (int j = 0; j < i; j++)
                p = p->next;
        } else {
            p = &dummy;
            for (int j = n; j > i; j--)
                p = p->prev;
        }
        return (p);
    }
    // get(i)/set(i,x) ops are now also easy -
    // first find the i1th node - then get or set its value!
    T get(int i) {
        return getNode(i)->x;
    } // ah -- pointers -- must be how JS is done too?
    T set(int i, T x) {
        Node<T>* u = getNode(i);
        T y = u->x;
        u->x = x;
        return y;
    }

    // Run time of these are O(1 + min(i, n-i)) -- time it takes to find a node
    // 3.2.1 Adding/Removing
    // insert a node `u` before node `w` - just set u.next = w, u.prev = w.prev
    // then we just adjust u.prev.next/u.next.prev (see drawing in notes)

    Node<T>* addBefore(Node<T>* w, T x) {
        Node<T>* u = new Node<T>;
        u->x = x;
        // insert and update new node refs
        u->prev = w->prev;
        u->next = w;
        // adjust old refs
        u->prev->next = u;
        u->next->prev = u;
        n++;
        return u;
    }

    // Now, the list op, add(i, x) is trivial --
    // 1. find ith node
    // 2. insert new node that contains x before
    void add(int i, T x) { addBefore(getNode(i), x); }
    // non-constant run time of add == time to find ith node -> O(1 + min(i,
    // n-i))

    // Removing a node from DLList:
    // just need to adjust pointers at w.next/w.prev to skip over w.
    void remove(Node<T>* w) {
        w->prev->next = w->next;
        w->next->prev = w->prev;
        delete w;
        n--;
    }
    // and now remove(i) is trivial - again
    // 1. find the ith node
    // 2. remove node there
    void remove(int i) {
        Node<T>* w = getNode(i);
        T x = w->x;
        remove(w);
        return x;
    }
    // again - the expensive part is locating the node
    // Summary - 
    // A DLList implements the List interface
    // get(i), set(i, x), add(i, x), and remove(i) ops run in
    // O(1 + min{i, n - i}) time
    // ignoring retrieval -- all ops run in constant time
    
    // compared to ArrayList - Searching Array is constant, adding/removal items is not
    // LinkedList best when 👀 
    // - references to list nodes can be obtained thru external means
    // - e.g. pointers to nodes of a linkedlist stored in a USet.
    //  - removal of item x from LL, node containing x can be grabbed quickly using Uset
    //  - node can be removed from list in constant time
};
