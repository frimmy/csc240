#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int priority;
    Student(std::string n, int p) : name(std::move(n)), priority(p) {
        std::cout << "  [new]    " << name << "\n";
    }
    ~Student() { std::cout << "  [delete] " << name << "\n"; }
};

// Two containers that BOTH believe they own their contents.
struct OwningTable {
    std::vector<Student*> items;
    void add(Student* s) { items.push_back(s); }
    ~OwningTable() { for (Student* s : items) delete s; }
};

int main(int argc, char**) {
    if (argc > 1) {   // dangling-pointer demo
        std::cout << "--- DANGLING POINTER ---\n";
        Student* alice = new Student("Alice", 5);
        std::vector<Student*> table{alice};
        std::vector<Student*> queue{alice};
        std::cout << "  queue drops Alice and deletes her:\n";
        delete queue[0];
        queue.clear();
        std::cout << "  table still holds the pointer. Reading it:\n";
        std::cout << "  table[0]->priority = " << table[0]->priority
                  << "   <-- reading freed memory\n";
        return 0;
    }
    std::cout << "--- DOUBLE FREE ---\n";
    Student* bob = new Student("Bob", 3);
    {
        OwningTable hashTable;
        OwningTable priorityQueue;
        hashTable.add(bob);
        priorityQueue.add(bob);      // same object, second owner
        std::cout << "  both containers going out of scope now:\n";
    }
    std::cout << "  (if you see this line, you got lucky)\n";
    return 0;
}
