#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;


int main()
{
    //VECTOR
    /*vector<int> a;
    for(int i = 0;i<5;i++)
    {
	a.push_back(i+2);
    }
    for(auto i = a.begin();i!=a.end();++i)
    {
	cout << "Value of Vector at = " << *i << endl; 
    }
    //vector<int>::iterator i; // for normal
    vector<int>::reverse_iterator i; // for reverse
    cout << "Using iterator Size = "<< a.size() << endl;
    //for(i = a.begin();i != a.end();++i) // for normal 
    for(i = a.rbegin();i != a.rend();++i) // for reverse 
    {
        cout << "Value of Vector at = " << *i << endl;
    }*/
    map<int,string> b;
    b.insert(pair<int,string>(1,"Hello"));
    map<int,string>::iterator it = b.begin();
    cout << "Value of first = " << it->first << " Value of second " << it->second << endl;

    return(0);
}

