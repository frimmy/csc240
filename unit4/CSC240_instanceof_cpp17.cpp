/*
    CSC 240 - C++ Data Structures
    Type Identification in C++17

    Ivan Temesvari
    Fall 2026

    Purpose:  Demonstrates how to determine what type a templated or polymorphic
              variable actually holds, and shows which technique belongs in
   which situation. Input:    None. Output:   Console demonstration of
   compile-time and run-time type checks.

    Build:    g++ -std=c++17 -Wall CSC240_instanceof_cpp17.cpp -o instanceof

    There are two different questions here and they have two different answers:

      1. COMPILE TIME - "what is T in this template?"      -> if constexpr +
   is_same_v costs nothing at run time
      2. RUN TIME     - "what does this pointer point at?" -> dynamic_cast
                                                              requires a virtual
   function

    Using the compile-time tool for a run-time question gives a WRONG ANSWER
    rather than a compile error. See demoTheTrap() below.
*/

#include <iostream>
#include <string>
#include <type_traits>

// ---------------------------------------------------------------------------
// COMPILE-TIME CHECKS
// C++17 note: is_same_v<A,B> replaces is_same<A,B>::value.
//             The _v suffix works for every type trait; _t replaces ::type.
// ---------------------------------------------------------------------------

// "Is T exactly this type?"  Use this when you mean exact match.
template <class Base, class T> inline bool isExactly(const T&) {
    return std::is_same_v<Base, T>;
}

// "Is T this type or derived from it?"
// Note: is_base_of_v<A, A> is TRUE - a class counts as its own base.
// Note: is_base_of_v is FALSE for non-class types such as int.
template <class Base, class T> inline bool isKindOf(const T&) {
    return std::is_base_of_v<Base, T>;
}

// ---------------------------------------------------------------------------
// RUN-TIME CHECK
// Requires Base to have at least one virtual function (a virtual destructor
// is the usual choice). Unlike the checks above, this inspects the OBJECT.
// ---------------------------------------------------------------------------
template <class Base, class T> inline bool instanceOf(const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

// ---------------------------------------------------------------------------
// A polymorphic hierarchy to test against
// ---------------------------------------------------------------------------
class Animal {
  public:
    virtual ~Animal() = default; // makes the class polymorphic
    virtual void speak() const { std::cout << "Some generic animal sound\n"; }
};

class Dog : public Animal {
  public:
    void speak() const override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
  public:
    void speak() const override { std::cout << "Meow!\n"; }
};

// ---------------------------------------------------------------------------
// C++17 compile-time dispatch with if constexpr
//
// This is the modern answer to "my template should behave differently for
// different types." The branches that do not apply are discarded BEFORE
// compilation finishes, so:
//    - there is no run-time cost at all, and
//    - a branch may contain code that would not compile for other types.
//
// An ordinary if would NOT work here: every branch must compile, so calling
// .size() on an int would be an error even though that branch never runs.
// ---------------------------------------------------------------------------
template <typename T> std::string describe(const T& value) {
    if constexpr (std::is_same_v<T, std::string>)
        return "a string of length " + std::to_string(value.size());
    else if constexpr (std::is_integral_v<T>)
        return "an integer";
    else if constexpr (std::is_floating_point_v<T>)
        return "a floating-point number";
    else
        return "some other type";
}

// ---------------------------------------------------------------------------
void identifyAnimal(const Animal& animal) {
    if (instanceOf<Dog>(&animal))
        std::cout << "This is a dog.\n";
    else if (instanceOf<Cat>(&animal))
        std::cout << "This is a cat.\n";
    else
        std::cout << "This is some other type of animal.\n";
}

// ---------------------------------------------------------------------------
void demoTheTrap() {
    Dog realDog;
    const Animal& ref = realDog; // static type Animal, dynamic type Dog

    std::cout << "The object below really IS a Dog. Asking two ways:\n";
    std::cout
        << "  isKindOf<Dog>(ref)     -> " << isKindOf<Dog>(ref)
        << "   <-- WRONG. T deduced as Animal; never looks at the object.\n";
    std::cout << "  instanceOf<Dog>(&ref)  -> " << instanceOf<Dog>(&ref)
              << "   <-- correct. Asks the object what it is.\n\n";
}

// ---------------------------------------------------------------------------
int main() {
    int num = 7;
    std::string number = "7";

    std::cout << "--- Compile-time checks ---\n";
    std::cout << "isExactly<std::string>(num)    -> "
              << isExactly<std::string>(num) << "\n";
    std::cout << "isExactly<std::string>(number) -> "
              << isExactly<std::string>(number) << "\n";
    std::cout << "is_base_of_v<string,string>    -> "
              << std::is_base_of_v<
                     std::string,
                     std::string> << "   (a class counts as its own base)\n\n";

    std::cout << "--- if constexpr dispatch ---\n";
    std::cout << "  42       -> " << describe(42) << "\n";
    std::cout << "  3.14     -> " << describe(3.14) << "\n";
    std::cout << "  \"hello\"  -> " << describe(std::string("hello")) << "\n\n";

    std::cout << "--- Run-time checks ---\n";
    Dog myDog;
    Cat myCat;
    Animal someAnimal;
    identifyAnimal(myDog);
    identifyAnimal(myCat);
    identifyAnimal(someAnimal);
    std::cout << "\n";

    std::cout << "--- The trap ---\n";
    demoTheTrap();

    return 0;
}
