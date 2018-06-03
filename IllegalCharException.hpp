#pragma once
#include<iostream>
using namespace std;

class IllegalCharException{
/*
*Declarence of varible
*/        
    char c;
public:
/*
*Declarence on function
*/     
    IllegalCharException(const char& c);
    char theChar() const;
};
