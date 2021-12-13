#include <iostream>

using namespace std;

class A
{
    private:
	int x,y;
	static int s ; //  Static Variable 
    public:
	A(int a = 0, int b = 0):x(a),y(b){cout << "Inside A constructor " << endl; }
	//A(int a = 0, int b = 0):x(10),y(x+10){} //-- VALID    - 
	//A(int a = 0, int b = 0):x(y+10),y(10){} //-- NOTVALID - Initialization from left to right 
	void print();
	static void print_s()
	{
	    cout << "Value of S before = " << s << endl;
	    s = 4;
	    cout << "Value of S after = " << s << endl;
	}
	virtual ~A(){cout << "Destructor A Called " << endl;}
};
int A::s = 2;
class B
{
    private:
	A a;
	int &t;
    public:
	B(int, int,int&);
	void print(){cout << "Value of  T = " << t << "\n" << "Calling A print " << endl; a.print();}
	~B(){cout << "Destructor B Called " << endl;}
};
B::B(int a,int b,int& c):a(a,b),t(c){cout <<"Value of  T = " << t << "\n" << "Inside B constructor " << endl;}

void A::print()
{
    cout << "Inside A print \n"<<"Value of X = " << x << " Value of Y = " << y << endl;
}
class C : public A 
{
    public:
	C(int x,int y):A(x,y){cout <<"Inside C constructor " << endl;}
	~C(){cout << "Destructor C Called " << endl;}
};

int main(int argc , char ** argv)
{
    cout << "Total Argument = " << argc << endl;
    for (int i = 0 ; i < argc ; i++)
    {
	cout << "Argumet value " << i+1 << " = " << argv[i] << endl;
    }
    //POINTER CHAR 
    /*char str[] = "HelaoAll";
    cout << "str Size " << sizeof(str) << " \nAddress " << &str << " \nstoring " << str << endl;
    char *ptr = str;//1
    //char *ptr = "Hello";//2
    cout << "ptr Size " << sizeof(ptr) << " \nAddress " << &ptr << " \nstoring " << *ptr << endl;
    ptr++;
    cout << "ptr Size " << sizeof(ptr) << " \nAddress " << &ptr << " \nstoring " << *ptr << endl;
    ptr++;
    cout << "ptr Checking *ptr++ = " << *ptr++ << endl;
    cout << "ptr Checking *ptr = " << *ptr << " *(ptr++) = " << *(ptr++) << endl;
    //Below line only in case of 1 not 2 
    cout << "Checking *ptr = " << *ptr << " (*ptr)++ = " << (*ptr)++ << endl; //occur when a process is trying to access memory that the CPU cannot physically address
    cout << "ptr Checking *ptr = " << *ptr << " *(ptr++) = " << *(ptr++) << endl;
    cout << "str Size " << sizeof(str) << " \nAddress " << &str << " \nstoring " << str << endl;
    return (0);*/

    /*// 2D Array to Pointer 
    int a[3][3] = {{1,2,3},{4,5,6}};
    int * ptr = &a[0][0];
    cout << "* ptr = " << *ptr << endl;
    cout << "*++ptr = " << *++ptr << endl;*/

    /*// MAlloc, calloc, realloc
    int *ptr;
    ptr = (int * ) malloc (5 * sizeof(int));
    int *ptr_f = ptr;
    for(int i = 0 ; i< 5;i++)
    {
	ptr[i] = i+1;
    }
    for(int i = 0 ; i< 5;i++)
    {
	cout << "Ptr " << i << " value = " << *ptr << endl;
	++ptr;
    }
    int *ptr_c = (int *) calloc(5,sizeof(int));
    int * ptr_f1 = ptr_c;
    for(int i = 0 ; i< 5;i++)
    {
        cout << "Calloc Ptr " << i << " value = " << *ptr_c << endl;
        ++ptr_c;
    }
    ptr_c = (int *) realloc (ptr_f1, 10 * sizeof(int));
    ptr_f1 = ptr_c;

    cout << "After realloc " << endl;
    for(int i = 0 ; i< 10;i++)
    {
        cout << "Calloc Ptr " << i << " value = " << *ptr_c << endl;
        ++ptr_c;
    }


    free(ptr_f);
    free(ptr_f1);*/

    //NEW , DELETE , NOTHROW 
    /*int *p, *q , *r;
    p = new(nothrow) int;
    if(p != NULL)
    {
	*p = 16;
	cout << "Value of P = " << *p << endl;
    }
    q = new(nothrow) int(6);
    if(q != NULL)
    {
        cout << "Value of Q = " << *q << endl;
    }
    r = new(nothrow) int[5];
    if(r != NULL)
    {
        for (int i = 0; i < 5; i++)
            r[i] = i+5;

        cout << "Value store in block of memory in R : \n";
        for (int i = 0; i < 5; i++)
            cout << "Value of " << i+1 << " element = " << r[i] << endl;
    }
    delete p;// Deletes memory and calles destructor marked as virtual 
    delete q;
    delete[] r;*/

    // CLASS 
    /*A a(2,3);
    a.print();
    int x = 6;
    B b(4,5,x);
    b.print();
    C c(7,8);
    c.print();*/

    //STATIC 
    /*A::print_s();*/

   // VTABLE , VPTR 
   A* aa = new(nothrow) C(2,3);
   aa->print(); 
   delete aa;// Deletes memory and calles destructor marked as virtual
}
