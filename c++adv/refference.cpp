#include <iostream>

using namespace std;

int main()
{
    int x{5};
    int &y{x}; // refference always needs a initializer
    cout << "X = " << x << " Y = " << y << endl;
    y = 10;
    cout << "X = " << x << " Y = " << y << endl;
    // int &z;

    return (0);
}