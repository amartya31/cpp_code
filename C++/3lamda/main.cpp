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
    auto add = [](int a,int b)->int{
        return (a+b);
    };

    int sum = add(2,3);

    cout << "Sum Value = " << sum << endl;
    
    // Lamda function by value 

    auto mul = [](int a)->int{
        return a*2;
    };
    sum = mul(sum);
    cout << "Sum Value = " << sum << endl;

    // Lamda by reference 

    auto diff = [](int &n){
        n = n/2;
    };

    diff(sum);
    cout << "Refference Vallue = " << sum  << endl;

    auto mulR = [](int *n){
        *n = (*n) * 2;
    };

    mulR(&sum);
    cout << "Refference Vallue = " << sum  << endl;

    // Capture [] in lamda 
    int test = 5;
    // By value 
    auto showCapV = [test](){
        int test1 =  test + 1; // note in value is constant 
        cout << "Test by Value " << test1 << endl;
    };
    showCapV();
    cout <<"Test value = " << test << endl;
    // By reference 
    auto showCapR = [&test](){
        test =  test + 1; // note in value is constant 
        cout << "Test by Reference " << test << endl;
    };
    showCapR();
    cout <<"Test value = " << test << endl;
    auto showSum = [&](){
        sum = sum +1;
        cout << "Sum by refernce  " << sum << endl;
    };
    showSum();
    cout <<"Test val = " << test  << "  Sum = " << sum << endl;




    return(0);
}