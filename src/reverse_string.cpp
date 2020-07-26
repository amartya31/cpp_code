#include <iostream>

using namespace std;

/*************************************************/
/* FUNCTION DESCRIPTION */
/* To reverse string */
/*************************************************/
void reverse_str(char *str , int len)
{
  char temp;
  int initial = 0 ;
  len-- ;
  while ( initial <= len )
  {
    temp = *(str + initial) ;
    *(str + initial) = *(str + len) ;
    *(str + len) = temp ;
    initial++ ;
    len-- ;
  }
}

/*************************************************/
/* FUNCTION DESCRIPTION */
/* To calculate string length */
/*************************************************/
void str_length( char *str , int *len)
{
  while ( *(str + *len ) != '\0' )
  {
    *len = *len + 1;
  }
  cout << "Length of String inside function = " << *len << endl;
}

/*************************************************/
/* FUNCTION DESCRIPTION */
/* Main function */
/*************************************************/
int main()
{
  char str[] = "Hello";
  cout << "String = " << str << endl;
  int len = 0;
  str_length ( str , &len ) ;
  cout << "Length of String = " << len << endl;
  reverse_str ( str , len );
  cout << "String reversed = " << str << endl;
  return ( 0 );
}
