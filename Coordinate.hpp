#pragma once
#include <iostream>
using namespace std;

class Coordinate{
/*
*Declarence of varible
*/       
    private:
        uint r;
        uint c;
    public:
/*
*Declarence on function
*/       
        Coordinate();
        Coordinate(uint, uint);
        uint GetRow() const;
        uint GetColumn() const;
        const Coordinate& operator=(const Coordinate&);
};
