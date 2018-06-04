
#include "Board.h"
using namespace std;
#include <fstream>
#include "RGB.h"
#include <string>
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
    //throw IllegalCoordinateException (cor.GetRow(),cor.GetColumn());
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
bool existFile (string nameFile) {
    ifstream f(nameFile);
    if(f)
        return true;
    return false;
}
string  Board:: draw(unsigned int pixels){

    int i = 1;
    string nameFile="cpp";
    nameFile+=to_string(i);
    nameFile+=".ppm";

    while(existFile(nameFile)){
       i++;
        //nameFile.clear();
        nameFile="cpp";
        nameFile+=to_string(i);
        nameFile+=".ppm";
    }
  ofstream imageFile(nameFile, ios::out | ios::binary);
  imageFile << "P6" << endl << pixels <<" " << pixels << endl << 255 << endl;
  RGB image[pixels*pixels];
  for (int j = 0; j < pixels; ++j)  {  // row
    for (int i = 0; i < pixels; ++i) { // column
    
     image[pixels*j+i].red = 255;
     image[pixels*j+i].green = 255;
     image[pixels*j+i].blue = ( (i*i+j*j) % 256);
    }
  }
//for over the board
for(uint i=0;i<this->len;++i){
    for(uint j=0;j<this->len;++j){
        switch (brd[i][j]){
            case 'X':
            makeX(image,i,j,pixels);
            break;
            case 'O':
            makeO(image,i,j,pixels);
            break;
        }
    }
}
  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*pixels*pixels);
  imageFile.close();
      return nameFile;
}
void Board:: makeX(RGB image[],uint Row,uint Col,uint pixels){
    int brdsize=pixels/this->len;
int RowStart=(Row+0.25)*brdsize, Colstart=(Col+0.25)*brdsize;
	int Colend=(Col+0.75)*brdsize;   
	for(int i=0; i<0.5*brdsize; i++)
	{
		//make the negetive line blue
		for(int k=i-1; k<i+2; k++){
       		image[(i+RowStart)*pixels+Colstart+k].red=127;
		
		image[(i+RowStart)*pixels+Colstart+k].green=136;
		
    		image[(i+RowStart)*pixels+Colstart+k].blue=229;
		}
	}
	for(int i=0; i<0.5*brdsize; i++)
	{
		//make the positive line red
        image[(i+RowStart)*pixels+Colend-i-1].red=248;
		image[(i+RowStart)*pixels+Colend-i].red=248;
		image[(i+RowStart)*pixels+Colend-i+1].red=248;
		image[(i+RowStart)*pixels+Colend-i-1].green=11;
		image[(i+RowStart)*pixels+Colend-i].green=11;
		image[(i+RowStart)*pixels+Colend-i+1].green=11;
        image[(i+RowStart)*pixels+Colend-i-1].blue=11;
		image[(i+RowStart)*pixels+Colend-i].blue=11;
		image[(i+RowStart)*pixels+Colend-i+1].blue=11;
	}
}
void Board:: makeO(RGB image[],uint indrow,uint indcol,uint pixels){
    int brdsize=pixels/this->len;
    int rad=brdsize/3;
    int rowCenter= (indrow+0.5)*brdsize, colCenter=(indcol+0.5)*brdsize;
	int rowStart=indrow*brdsize, colStart=indcol*brdsize;
	int rowEnd=(indrow+1)*brdsize, colEnd=(indcol+1)*brdsize;
	for(int i=rowStart; i<rowEnd; i++)
	{
		for(int j=colStart; j<colEnd; j++)
		{	//make green circle
			int dist=sqrt((i-rowCenter)*(i-rowCenter)+(j-colCenter)*(j-colCenter));//
			if(dist==rad){
                image[i*pixels+j-1].red=27;
		        image[i*pixels+j].red=27;
		        image[i*pixels+j+1].red=27;
		        image[i*pixels+j-1].green=237;
		        image[i*pixels+j].green=237;
	        	image[i*pixels+j+1].green=237;
                image[i*pixels+j-1].blue=40;
	        	image[i*pixels+j].blue=40;
	        	image[i*pixels+j+1].blue=40;
            } 
		}
	}
}
