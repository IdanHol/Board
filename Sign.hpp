#pragma once

#include <iostream>
#include "IllegalCharException.hpp"
using namespace std;
class Sign{
/*
*Declarence of varible
*/     
    char a;
 /*
*Declarence on function
*/    
    public:
    Sign(const char&);
    Sign();
    
       operator char();

    char GetSign() const;
   Sign& operator=(const char&);
   Sign&  operator=(const Sign& );
   friend bool  operator==(const Sign& s,const char& );
   friend ostream& operator<<(ostream& os, Sign const& );
};
/*
*Check if sign equal to other
*/ 
inline bool  operator==(const Sign& s,const char& c){

  return s.GetSign()==c;
   
}
