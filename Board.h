#pragma once
#include <iostream>
#include "Sign.hpp"
#include "Coordinate.hpp"
#include "IllegalCoordinateException.hpp"
#include "RGB.h"
#include <math.h>
using namespace std;

class Board{
/*
*Declarence of varible
*/    
    int len;
    Sign** brd;
/*
*Declarence on function
*/    
public:
    uint size()const;
    Board(int);
    Board();
    Board(const Board& other);
    Sign& operator[](const Coordinate&) const;
    Board& operator=(const char& c);
    Board& operator=(const Board&);
    friend ostream& operator<< (ostream& out, const Board &other);
    friend istream& operator>> (istream& in,  Board &other);
    ~Board();
    
    void makeX(RGB[],uint ,uint ,uint );
    void makeO(RGB[],uint ,uint ,uint);
    string draw(unsigned int);
};
/*
*Print the Board
*/
inline ostream&  operator<< (ostream& out, const Board &other){
    for(int i=0;i<other.len;++i){
        for(int j=0;j<other.len;++j){
            out <<other.brd[i][j];
        }
        out << '\n';
    }
   
    return out;

}
inline istream&  operator>> (istream& in,Board &other){
   std::string line;
      uint i=0;uint j;
   getline(in,line);
    int index=0,size=line.size()-1;
    if(line.size()==1)
        size=1;
      Board temp(size);
         for(j = 0; j <size; j++){
         
            i=index;
            Coordinate c{i,j};
            temp[c] = line[j];
        }
       index++;
        while(getline(in,line)){
        for(j = 0; j < size; j++){
         
            i=index;
            Coordinate c{i,j};
            temp[c] = line[j];
        }
       index++;
      
        
    
        }
   other = temp;
    return in;

}