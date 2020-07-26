#include <iostream>

using namespace std;

class Base
{
  public:
    int x = 1 ;
  protected:
    int y = 2 ;
  private:
    int z = 3 ;
};
class derived_public : public Base 
{
  public:
  // x is public
  // y is protected
  // z is not accessible from derived_public
  void show_val()
  {
  cout << "derived_public" << endl;
  cout << "Value of X = " << x  << endl;
  cout << "Value of Y = " << y  << endl;
  //cout << "Value of Z = " << z  << endl;
  }
};
class derived_private : private Base
{
  public:
  // x is protected
  // y is protected
  // z is not accessible from derived_private
  void show_val()
  {
  cout << "derived_private" << endl;
  cout << "Value of X = " << x  << endl;
  cout << "Value of Y = " << y  << endl;
  //cout << "Value of Z = " << z  << endl;
  }
};
class derived_protected : protected Base
{
  public:
  // x is private
  // y is private
  // z is not accessible from derived_protected
  void show_val()
  {
  cout << "derived_protected" << endl;
  cout << "Value of X = " << x  << endl;
  cout << "Value of Y = " << y  << endl;
  //cout << "Value of Z = " << z  << endl;
  }
};
class derived_public2 : public derived_protected
{
  public:
  // x is public
  // y is protected
  // z is not accessible from derived_public
  void show_val1()
  {
  cout << "derived_public2" << endl;
  cout << "Value of X = " << x  << endl;
  cout << "Value of Y = " << y  << endl;
  //cout << "Value of Z = " << z  << endl;
  }
};

int main()
{
  derived_public pub;
  pub.show_val();
  derived_private pri;
  pri.show_val();
  derived_protected pro;
  pro.show_val();
  derived_public2 pub2;
  pub2.show_val1();
  return ( 0 ) ;
}
