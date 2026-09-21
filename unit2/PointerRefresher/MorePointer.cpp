// 3 ways to pass C++ args to a func

#include <iostream>
using namespace std;

int main() {
    int nums[2][3] = {{16, 18, 20}, {25, 26, 27}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "pointer fun: " << *(*(nums + i) + j) << endl;
        }
    }
}
