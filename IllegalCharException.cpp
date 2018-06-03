#include <iostream>
#include "IllegalCharException.hpp"
using namespace std;
/*
*Retuern the illegal char
*/
IllegalCharException::IllegalCharException(const char& c){
    this->c=c;
}
char IllegalCharException:: theChar() const{
    return c;
}
