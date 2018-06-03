#include "Coordinate.hpp"
using namespace std;
/*
*Default Constructor
*/
Coordinate::Coordinate(){
    this->r=0;
    this->c=0;
}
/*
*Constructor
*/
Coordinate::Coordinate(uint r,uint c){
    this->r=r;
    this->c=c;
}
/*
*Set and Get Function
*/
uint Coordinate:: GetRow() const {return this->r;}
uint Coordinate:: GetColumn() const {return this->c;}
const Coordinate& Coordinate:: operator=(const Coordinate& other){
    this->r=other.r;
    this->c=other.c;
    return *this;
}
