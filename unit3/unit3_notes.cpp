// Stack abstract class
template <typename E> class Stack {
  private:
    void operator=(const Stack&) {} // Protect assignment
    Stack(const Stack&) {}          // Protect copy constructor
  public:
    Stack() {}          // Default constructor
    virtual ~Stack() {} // Base desctuctor

    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;

    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E& it) = 0;

    // Remove the element at the top of the stack.
    // return: The element at the top of the stack.
    virtual E pop() = 0;

    // Return: A copy of the top element.
    virtual const E& topValue() const = 0;

    // Return: The number of elements in the stack.
    virtual int length() const = 0;
};

// * stack remove elements in reverse order of their arrival aka LIFO
// * accessible elem = `top`
// * elements are *`pushed` onto stack, not inserted!
// * when removed, element is `popped`

// TWO approaches to stacks: array-based vs linked

// 4.2.1 Array-based stacks
// Array-based stack impl
template <typename E> class AStack : public Stack<E> {
  private:
    int maxSize;  // max size of stack
    int top;      // index for top elem
    E* listArray; // array holding stack of elements

  public:
    AStack(int size = defaultSize) // Constructor
    {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    ~AStack() { deleted[] listArray; } // Destructor
    void clear() { top = 0; }          // Reinitialize

    void push(const E& it) { // Put "it" on Stack
        Assert(top != maxSize, "Stack is full");
        listArray[top++] =
            it; // we add elem to free position and THEN increment
    }

    E pop() { // Pop top element
        Assert(top != 0, "Stack's empty");
        return listArray[--top]; // we first decrement top and THEN and removes
                                 // the element
    }

    const E& topValue() const { // Return top element
        Assert(top != 0, "Stack is empty");
        return listArray[top - 1];
    }

    int length() const { return top; } // Return length
};

// 4.2.2 Linked Stacks
// Linked stack impl
// Singly linked list node
template <typename E> class Link {
  public:
    E element;  // value for the node
    Link* next; // Pointer to next node in list
    // constructors
    Link(const E& elemval, Link* nextval = NULL) {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval = NULL) { next = nextval; }
};
template <typename E> class LStack : public Stack<E> {
  private:
    Link<E>* top; // Pointer to first element
    int size;     // Number of elements

  public:
    LStack(int sz = defaultSize) // Constructor
    {
        top = NULL;
        size = 0;
    }
    ~LStack() { clear() } // Destructor
    void clear() {        // reinitialize
        while (top != NULL) {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E& it) { // Put "it" on stack
        top = new Link<E>(it, top);
        size++;
    }

    E pop() { // Remove "it" from stack
        Assert(top != NULL, "Stack is empty");
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    const E& topValue() const { // Return top value
        Assert(top != 0, "Stack is empty");
        return top->element;
    }

    int length() const { return size; } // Return length
};

// can avoid recursion with iteration
// using a stack, we can avoid recursion!
long fact(int n, Stack<int>& S) {
    // To fit n! in a long variable, require n <= 12
    Assert((n >= 0) && (n <= 12), "Input out of range");
    while (n > 1)
        S.push(n--); // Load up the stack
    long result = 1;
    while (S.length() > 0)
        result = result * S.pop(); // Compute
    return result;
}

// not always possible to replace recursiojn w/ iteration
// * recursion unavoidable when we need multiple branches
// * i.e. mergesort/quicksort
// * but we can always imitate recursion with stacks
// * can use stack implementations of recursion when the sub-problem's
// * ie. tiny(Quicksort)

// 4.3 Queues

// AST for Queues:
template <typename E> class Queue {
  private:
    void operator=(const Queue&) {} // Protect assignment
    Queue(const Queue&) {}          // Protect copy constructor

  public:
    Queue() {}        // default
    virtual ~Queue {} // Base destructor

    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements
    virtual void clear() = 0;

    // Place an element at rear of queue
    // it: the element being enqueued.
    virtual void enqueue(const E&) = 0;

    // Remove and return element at the front of the queue.
    // Return: the element at front of queue
    virtual E dequeue() = 0;

    // Return: a copy of the front element.
    virtual const E& frontValue() const = 0;

    // Return: the number of elements in the queue.
    virtual int length() const = 0;
};

// 4.3.1 Array-based queues
// * tricky ... we can't just convert array-based list(inefficient)
// * avoid inefficient ops by relaxing requirement that elements occupy first
// * n/last n positions. 💡
// NOTE: BUT how do we know if queue is empty/full?!
//    - `front` stores arr idx for front
//    - `rear` stores arr idx for rear
//  - our queue impl has an array one space larger than the queue can hold to
//  distinguish empty queues from full ones
// -  `maxSize` used to control the circular motion of the queue
// -  `rear` set to position of current rear element, front of the current front
// element
// - front is definedas toward lower number positions in the arr, rear is higher
// - `enqueue` increments the REAR pointer (modulus size) and dequeue increments
// the FRONT pointer

// Array-based queue implementation
template <typename E> class AQueue : public Queue<E> {
  private:
    int maxSize;  // Max size of queue
    int front;    // idx of front elem
    int rear;     // idx of rear elem
    E* listArray; // Array holding queue elements

  public:
    AQueue(int size = defaultSize) { // Constructor
        // make list array one position larger for empty slot
        maxSize = size + 1;
        rear = 0;
        front = 1;
        listArray = new E[maxSize];
    }

    ~AQueue() { delete[] listArray; } // Destructor

    void clear() {
        // Reinitialize
        rear = 0;
        front = 1;
    }

    void enqueue(const E& it) { // Put "it" in queue
        Assert((rear + 2) % maxSize != front, "Queue is full");
        rear = (rear + 1) % maxSize; // circular increment
        listArray[rear] = it;
    }

    E dequeue() { // take element out
        Assert(length() != 0, "Queue is empty");
        E it = listArray[front];
        front = (front + 1) % maxSize; // circular increment
        return it;
    }

    const E& frontValue() const { // Get front value
        Assert(length() != 0, "Queue is empty");
        return listArray[front];
    }

    virtual int length() const // return length
    {
        return ((rear + maxSize) - front + 1) % maxSize;
    }
};
// 4.3.2 - Linked Queues - Fortunately -- these're more straightfwd!
// * we can adapt the LList
// * `front` and `rear` are pointers to front and rear queue elems
// * use a header link node for simple enqueue ops
// * on init, `front`/`rear` point to header node, and front'll always point to
// the head node
// * enqueue places new lem in a link node at the end + advances rear
// * dequeue removes and returns the first elem of the list
// Linked queue impl
// this is impl where HEAD node empty to make insert easy
template <typename E> class LQueue : public Queue<E> {
  private:
    Link<E>* front; // ptr to front queue node
    Link<E>* rear;  // ptr to rear queue node
    int size;       // number of elems in queue

  public:
    LQueue(int sz = defaultSize) // Constructor
    {
        front = rear = new LInk<E>();
        size = 0;
    }

    ~LQueue() { // Destructor
        clear();
        delete front;
    }

    void clear() {                    // clear queue
        while (front->next != NULL) { // delete each link node
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }

    void enqueue(const E& it) { // puts elem on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }

    E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element;  // Store dequeued value
        Link<E>* ltemp = front->next; // hold dequeued link
        front->next = ltemp->next;
        if (rear == ltemp)
            rear = front; // Dequeue last element
        delete ltemp;
        size--;
        return it;
    }
};
