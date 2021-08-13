#include <iostream>
using namespace std;

class complex{
private:
    int a;
public:
    void setdata(int x){
        a = x;
    }
    void showdata(){
        cout << "DATA = " << a << endl;
    }
    complex operator +(complex c){
        complex temp;
        cout << "Data after adding "<< a << " 2nd val " << c.a << endl;
        int i = 0;
        i = a + c.a;
        temp.setdata(i);
        return temp;
    }
};

int main(){
    complex c1, c2, c3,c4;
    c1.setdata(3);
    c2.setdata(5);
    c3.setdata(2);
    c4 = c1 + c2 + c3;
    c4.showdata();
}
