#include <iostream>

using namespace std;

class test 
{
  private:
  int x , y , sum;

  public:
  test(int a , int b)/*Constructor called with value */
  {
    cout << "Constrcutor called " << endl;
    x = a;
    y = b;    
    cout << "Value of X = " << x << endl ;
    cout << "Value of Y = " << y << endl ;
  }
  void add_val()
  {
    sum = x + y ;
  }
  void print_sum()
  {
    cout << "Sum = " << sum << endl;
  }
  ~test()
  {
    cout << "Destructor called " << endl;
  }

};

int main()
{
  test val( 2 , 4 );
  val.add_val();
  val.print_sum();

  return( 0 );
}
