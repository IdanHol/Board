
#include "Board.h"
using namespace std;
#include <fstream>
#include "RGB.h"
/*
*Default Constructor
*/
Board::Board(){
    this->len=1;
    this->brd=new Sign*[1];
    for(int i=0;i<1;++i){
        this->brd[i]=new Sign[1];
    }
}
Board::Board(int len){
    this->len=len;
    this->brd=new Sign*[len];
    for(int i=0;i<len;++i){
        this->brd[i]=new Sign[len];
    }
}
/*
*Copy Constructor
*/
Board::Board(const Board& other){
    this->len=other.len;
    this->brd=new Sign*[other.len];
    for(int i=0;i<other.len;++i){
        this->brd[i]=new Sign[other.len];
        for(int j=0;j<other.len;++j){
           this->brd[i][j]=other.brd[i][j];
        }
    }
}
/*
*Return size
*/
 uint Board:: size()const{return this->len;}
/*
*Opreator to return Sign in Some Cooridnate
*/
Sign& Board:: operator[](const Coordinate& cor)const {
    if(cor.GetRow()<len&&cor.GetColumn()<len)
        return brd[cor.GetRow()][cor.GetColumn()];
    throw IllegalCoordinateException (cor.GetRow(),cor.GetColumn());
}
/*
*Opreator input to Change Sign in the Board
*/
Board& Board:: operator=(const char& c){
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            this->brd[i][j]=c;
        }
    }
    return *this;
}
/*
*Operator input to change the Board to other
*/
Board& Board:: operator=(const Board& b){
    this->~Board();
    this->len=b.len;
    this->brd=new Sign*[len];
    for(int i=0;i<len;++i){
        this->brd[i]=new Sign[len];
        for(int j=0;j<len;++j){
           this->brd[i][j]=b.brd[i][j];
        }
    }
    return *this;
}
/*
*Destractor
*/
Board::~Board(){
    for(int i=0;i<this->len;++i){
        delete[] brd[i];
    }
    delete[] brd;
}
string  Board:: draw(unsigned int pixels){
    const int dimx = pixels, dimy = pixels;
    string nameFile="cpp.ppm";
  ofstream imageFile(nameFile, ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[dimx*dimy];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
    
     image[dimx*j+i].red = 255;
     image[dimx*j+i].green = 255;
     image[dimx*j+i].blue = ( (i*i+j*j) % 256);
    }
  }
 

  makeX(image,0,0,pixels);
 
  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
      return (std::string) nameFile;
}
void Board:: makeX(RGB rgb[],uint Row,uint Col,uint numPixel){
    int brdsize=numPixel/this->len;
int RowStart=(Row+0.25)*brdsize, Colstart=(Col+0.25)*brdsize;
	int Colend=(Col+0.75)*brdsize;   
	for(int i=0; i<0.5*brdsize; i++)
	{   	
        rgb[(i+RowStart)*numPixel+Colstart+i-1].red=127;
		rgb[(i+RowStart)*numPixel+Colstart+i].red=127;
		rgb[(i+RowStart)*numPixel+Colstart+i+1].red=127;
		rgb[(i+RowStart)*numPixel+Colstart+i-1].green=136;
		rgb[(i+RowStart)*numPixel+Colstart+i].green=136;
		rgb[(i+RowStart)*numPixel+Colstart+i+1].green=136;
    	rgb[(i+RowStart)*numPixel+Colstart+i-1].blue=229;
		rgb[(i+RowStart)*numPixel+Colstart+i].blue=229;
		rgb[(i+RowStart)*numPixel+Colstart+i+1].blue=229;
	}
	for(int i=0; i<0.5*brdsize; i++)
	{
        rgb[(i+RowStart)*numPixel+Colend-i-1].red=248;
		rgb[(i+RowStart)*numPixel+Colend-i].red=248;
		rgb[(i+RowStart)*numPixel+Colend-i+1].red=248;
		rgb[(i+RowStart)*numPixel+Colend-i-1].green=11;
		rgb[(i+RowStart)*numPixel+Colend-i].green=11;
		rgb[(i+RowStart)*numPixel+Colend-i+1].green=11;
        rgb[(i+RowStart)*numPixel+Colend-i-1].blue=11;
		rgb[(i+RowStart)*numPixel+Colend-i].blue=11;
		rgb[(i+RowStart)*numPixel+Colend-i+1].blue=11;
	}
}
