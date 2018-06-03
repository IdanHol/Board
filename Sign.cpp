#include <iostream>
#include "Sign.hpp"
using namespace std;
/*
*Constructor
*/ 
Sign::Sign(const char& n){
  this->a=n;
}
/*
*Default Constructor
*/
Sign::Sign(){
  this->a='.';
}
/*
*Geter
*/
char Sign::GetSign() const{
 return this->a;
}
/*
*Opreator input to Change the char in the Sign 
*/
Sign& Sign:: operator=(const char& c){
if(c!='X'&&c!='O'&&c!='.')
  throw IllegalCharException(c);
else
  this->a=c;
return *this;
}
/*
*Opreator input to Change Sign with other sign
*/
Sign& Sign::operator=(const Sign& c)
{
  if(c.GetSign()!='X'&&c.GetSign()!='O'&&c.GetSign()!='.')
    throw IllegalCharException(c.GetSign());
  else
    this->a=c.GetSign();
  return *this;
}
/*
*print sign
*/
ostream& operator<<(ostream& os, Sign const& b)
{
    os << b.a;
    return os;
}
/*
*Opreator to create Sign insted char
*/
Sign::operator char()
{
 
    return a;
}
