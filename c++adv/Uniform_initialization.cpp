#include <iostream>
#include <string>

using namespace std;

int main()
{
    int p;     // uninitialized
    int b = 0; // initialized --  Copy initialization
    int c(5);  // direct initialized
    //= means copy initialization
    string a1;
    string a2("C++"); // direct initialized

    char d1[8];                        // uninitialized
    char d2[8] = {'\0'};               // initialized --  Copy initialization
    char d3[8] = {'a', 'b', 'c', 'd'}; // aggregated initialization --  Copy initialization
    char d4[8] = {"C++"};              // initialized --  Copy initialization

    // UNIFORM INITIALIZATION

    int i1{};
    cout << i1 << endl;

    char e1[8]{};
    cout << e1 << endl;

    char e2[8]{"Hello "};
    cout << e2 << endl;

    char *p1 = new char[8]{};
    char *p2 = new char[8]{"Hello"};
    cout << *p2 << endl
         << *(++p2) << endl;
    ++p2;
    cout << *p2 << endl;

    return (0);
}