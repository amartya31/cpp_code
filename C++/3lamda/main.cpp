#include <iostream>

using namespace std;

int main(){
    /*  Syntax 
            [capture](parameter_list) -> return_type {
            // lambda body
            } 
    */
   // Inline Lamda Function 
    []{ 
        cout << "Without any value " << endl;
    }(); // -> entry point of the data  

    int val = [](int n)->int{ // -> defines the parameter list 
        return n*2;
    }(5); // -> data passed 

    // lamda to add 2 numbers 
    auto add = [](int a,int b){
        return (a+b);
    }

    return(0);
}