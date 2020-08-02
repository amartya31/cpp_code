#include <iostream>

/* Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential 
 * information about the data to the outside world, hiding the background details or implementation. */

using namespace std ;


class abstraction 
{ 
    private: 
        int a, b; 
  
    public: 
      
        // method to set values of  
        // private members 
        void set(int x, int y) 
        { 
            a = x; 
            b = y; 
        } 
          
        void display() 
        { 
            cout<<"a = " <<a << endl; 
            cout<<"b = " << b << endl; 
        } 
}; 
  
int main()  
{ 
    abstraction abc; 
    abc.set(10, 20); 
    abc.display(); 
    return 0; 
} 
