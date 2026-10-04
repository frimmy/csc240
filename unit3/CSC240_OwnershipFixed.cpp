#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int priority;
    Student(std::string n, int p) : name(std::move(n)), priority(p) {}
    ~Student() { std::cout << "  [delete] " << name << "\n"; }
};

// OWNER: allocates, and its destructor deletes. Exactly one of these.
class StudentTable {
public:
    Student* add(std::string name, int pr) {
        records.push_back(new Student(std::move(name), pr));
        return records.back();
    }
    void remove(Student* s) {
        for (size_t i = 0; i < records.size(); ++i)
            if (records[i] == s) { delete records[i]; records.erase(records.begin() + i); return; }
    }
    ~StudentTable() { for (Student* s : records) delete s; }
private:
    std::vector<Student*> records;
};

// OBSERVER: holds non-owning pointers. Its destructor deletes NOTHING.
class PriorityView {
public:
    void track(Student* s) { view.push_back(s); }
    void forget(Student* s) {
        for (size_t i = 0; i < view.size(); ++i)
            if (view[i] == s) { view.erase(view.begin() + i); return; }
    }
    void print() const {
        std::cout << "  view holds:";
        for (Student* s : view) std::cout << " " << s->name;
        std::cout << "\n";
    }
    ~PriorityView() = default;   // deliberately deletes nothing
private:
    std::vector<Student*> view;  // non-owning
};

int main() {
    StudentTable  table;     // owns
    PriorityView  byPriority; // observes

    Student* alice = table.add("Alice", 5);
    Student* bob   = table.add("Bob", 3);
    byPriority.track(alice);
    byPriority.track(bob);
    byPriority.print();

    std::cout << "  Alice withdraws. Observer forgets FIRST, then owner deletes:\n";
    byPriority.forget(alice);
    table.remove(alice);
    byPriority.print();

    std::cout << "  end of main - owner cleans up the rest:\n";
    return 0;
}
