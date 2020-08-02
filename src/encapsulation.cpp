#include <iostream>

/* Encapsulation is defined as wrapping up of data and information under a single unit. 
 * In Object Oriented Programming, 
 * Encapsulation is defined as binding together the data and the functions that manipulates them. */

using namespace std;

class Encapsulation
{
    private:
        int x;

    public:
        void set(int a)
        {
            x =a;
        }
        int get()
        {
            return x;
        }
};

int main()
{
    Encapsulation abc;

    abc.set(5);

    cout << "Value of private variable X = " << abc.get() << endl;
    return 0;
} 
