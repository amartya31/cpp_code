#include <iostream>

using namespace std;

int main()
{
    int x{5};
    cout << "Value of X = " << x << endl;
    int *p1 = &x; // same data type as pointer;
    cout << p1 << endl;
    void *p2 = &x; // VOID can point to anything
    cout << p2 << endl;

    cout << "P1 " << *p1 << " P2 " << *((int *)p2) << endl;

    // C++ 11 introduced nullptr instaed of NULL macro
    // NULL is a macro in C and pre-C++11. It is defined as zero in most compilers.
    int *p3 = NULL;
    int *p4 = nullptr;
    //*p4 = 5; wrong statement

    // Pointer to Constant - the data pointed by the pointer is constant and
    // cannot be changed. Although, the pointer itself can change and points
    // somewhere else (as the pointer itself is a variable).

    const int *p5{};

    int const *p7{&x};
    // Constant Pointer - the pointer points to a fixed memory location, and
    // the value at that location can be changed because it is a variable, but the pointer
    // will always point to the same location because it is made constant here.
    int y = 10;
    int *const p6{&y};
    cout << "p6 = " << *p6 << " p7 = " << *p7 << endl;

    // Constant Pointers to constants:In the constant pointers to constants, the data
    // pointed to by the pointer is constant and cannot be changed. The pointer itself
    // is constant and cannot change and point somewhere else.
    int z = 15;
    const int *const p8{&z};

    return (0);
}