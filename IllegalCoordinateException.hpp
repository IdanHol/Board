#pragma once
#include<iostream>
#include<string>
using namespace std;

class  IllegalCoordinateException{
/*
*Declarence of varible
*/     
    int r;
    int c;
public:
/*
*Declarence on function
*/     
    string theCoordinate() const;
    IllegalCoordinateException(int r,int c);
};
