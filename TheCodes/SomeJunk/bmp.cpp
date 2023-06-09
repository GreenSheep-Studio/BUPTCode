#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#pragma pack(1)

typedef unsigned short WORD;  //2???
typedef unsigned long DWORD;  //4???
typedef long LONG;            //4???
typedef unsigned char BYTE;   //1???
   

typedef struct tagBITMAPFILEHEADER { 
	WORD    bfType;	
	//��?????????????0X4D42
	DWORD   bfSize;		
	//��???????��??????????��
	WORD    bfReserved1;	
	//????????????0
	WORD    bfReserved2;	
	//????????????0
	DWORD   bfOffBits;		
	//��?????????��??????????��????????????
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
	DWORD  biSize;		//???????????????
	LONG   biWidth;		//��??????
	LONG   biHeight;		//��?????
	WORD   biPlanes;		//????��??????1
	WORD   biBitCount;              //????????????��????????1(??)??4(16?)??8(256?)??24(??//???)??
	DWORD  biCompression; 	//????????????0(?????)??1(BI_RLE8???)??2(BI_RLE4???)
	DWORD  biSizeImage;	//��????��??????????��
	LONG   biXPelsPerMeter;      //???????
	LONG   biYPelsPerMeter;      //????????
	DWORD  biClrUsed; 	//??????��??????
	DWORD  biClrImportant;      //��????????????????????
} BITMAPINFOHEADER;


int main()
{
	ifstream infile("face1.bmp",ios::binary);
	ofstream outfile("Greyface1.bmp",ios::binary);

	if (infile.fail())
		return 1;

	if (outfile.fail())
		return 1;

	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER bmpheader;

	
	infile.read((char*)&fileheader,sizeof(BITMAPFILEHEADER));
	infile.read((char*)&bmpheader,sizeof(BITMAPINFOHEADER));

	outfile.write((char*)&fileheader,sizeof(BITMAPFILEHEADER));
	outfile.write((char*)&bmpheader,sizeof(BITMAPINFOHEADER));

	unsigned char buf[3];
	infile.read((char*)buf,3);
	
	float a = 0.5;

	while(!infile.eof())
	{
		//?????????? RGB 
		buf[0] = 0.299*buf[0]+0.587*buf[1]+0.114*buf[2];
		buf[1] = buf[0];
		buf[2] = buf[0];

		/*buf[0]=pow(buf[0],a)*pow(255,1-a);
		buf[1]=pow(buf[1],a)*pow(255,1-a);
		buf[2]=pow(buf[2],a)*pow(255,1-a);*/

		outfile.write((char*)buf,3);
		infile.read((char*)buf,3);
	}

	infile.close();
	outfile.close();
	
	return 1;

}

