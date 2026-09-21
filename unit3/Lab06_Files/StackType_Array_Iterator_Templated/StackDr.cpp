// Test driver
// Adrian Frimpong
// Updated operator[]
// 2/17/2022
// Templated version

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "StackType.h"

using namespace std;

int main() {
    // Test with integer stack
    cout << "========== Testing Integer Stack ==========" << endl;
    try {
        StackType<int> stack;
        stack.Print();
        stack.Push(4);
        stack.Push(4);
        stack.Push(5);
        stack.Push(4);
        stack.Push(3);
        stack.Push(4);
        stack.Print();

        cout << "========= Testing ReplaceItem =========" << endl;
        ReplaceItem<int>(stack, 4, 99);
        cout << "========= Testing Identical =========" << endl;

        StackType<int> stack2;
        stack2.Push(4);
        stack2.Push(4);
        stack2.Push(5);
        stack2.Push(4);
        stack2.Push(3);
        stack2.Push(4);

        StackType<int> stack3;
        stack3.Push(4);
        stack3.Push(4);
        stack3.Push(5);
        stack3.Push(4);
        stack3.Push(3);
        stack3.Push(4);

        StackType<int> stack4;
        stack4.Push(4);
        stack4.Push(4);
        stack4.Push(5);
        stack4.Push(4);
        stack4.Push(3);
        stack4.Push(5);

        cout << (Identical(stack2, stack3) ? "matching" : "non-matching")
             << endl;
        cout << (Identical(stack2, stack4) ? "matching" : "non-matching")
             << endl;

    } catch (const FullStack& e) {
        cout << "Stack is full!" << endl;
    } catch (const EmptyStack& e) {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
