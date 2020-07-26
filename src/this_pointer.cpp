#include <iostream>

using namespace std ;

class compute
{
  public:
  int x;
  void compare(int x)
  {
    if (this->x == x)
    {
      cout << "Same " << endl;
    }
    else
    {
      cout << "Not same" << endl;
    }
  }
};

int main()
{
  int inp;
  compute data;
  data.x = 4;
  cout << "Enter the value for comparison " << endl;
  cin >> inp ;
  cout << "Value entered " << inp << endl;
  data.compare(inp);
  return ( 0 ) ;
}
