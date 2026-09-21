// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

// pointer should point to valid ADDRESS (not necessarily valid elems -
// arrays/strings) these would be invalid pointers uninitialized pointers ==
// invalid pointers

int main() {
    int* ptr1;
    int arr[10];

    int* ptr2 = arr + 20;

    // ptr1 is uninitialized -- becoming invalid pointer
    // and ptr2 is outta bounds so IT becomes invalid
    // NOTE: invalid pointers don't necessarily raise compile errors!

    // Null pointers
    // ptr which points nowhere - not just invalid address
    // 2 ways to assign ptrs as NULL:
    // 1.
    int* ptr1 = 0;
    // 0 in above code is used in a pointer context - not 0 as integer! 💡
    int* ptr2 = NULL;
}
