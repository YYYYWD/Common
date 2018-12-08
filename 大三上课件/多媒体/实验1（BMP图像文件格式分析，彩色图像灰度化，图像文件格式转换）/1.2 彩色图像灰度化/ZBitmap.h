#ifndef ZBITMAP_H
#define ZBITMAP_H
#include<iostream>
#include<string>
using namespace std;

typedef unsigned short UINT16;
typedef unsigned char UINT8;
typedef unsigned int DWORD; 
typedef DWORD LONG;
typedef unsigned short WORD;

typedef struct tagBITMAPFILEHEADER
{
	UINT16 bfType;    //bm  2�ֽ�
    DWORD bfSize;     //�ļ���С  4�ֽ�
    UINT16 bfReserved1; //�����ֶ�1  2�ֽ�
    UINT16 bfReserved2; //�����ֶ�2  2�ֽ�
    DWORD bfOffBits;    //������ƫ����  4�ֽ�
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize; //BITMAPINFOHEADER��Ҫ���ֽ��� 4�ֽ�
	LONG biWidth; //ͼ���� 4�ֽ�
	LONG biHeight; //ͼ��߶� 4�ֽ�
	WORD biPlanes; //ͼ��ƽ���� 2�ֽ�
	WORD biBitCount; //����/���� 2�ֽ�
	DWORD biCompression; //�Ƿ�ѹ�� 4�ֽ�
	DWORD biSizeImage; //ͼ����������С 4�ֽ�
	LONG biXPelsPerMeter; //ˮƽ�ֱ��� 4�ֽ�
	LONG biYPelsPerMeter; //��ֱ�ֱ��� 4�ֽ�
	DWORD biClrUsed; //ʹ�õĵ�ɫ���� 4�ֽ�
	DWORD biClrImportant;//��Ҫ��ɫ���� 4�ֽ�
} BITMAPINFOHEADER;

typedef struct tagRGBCOLOR
{
	UINT16 R;  //��ɫ���� 1�ֽ�
	UINT16 G;  //��ɫ���� 1�ֽ�
	UINT16 B;  //��ɫ���� 1�ֽ�
	UINT16 Alpha;//͸���� 1�ֽ�
}MYRGBCOLOR;

typedef struct tagPALETTE
{
	UINT16 R;  //��ɫ���� 1�ֽ�
	UINT16 G;  //��ɫ���� 1�ֽ�
	UINT16 B;  //��ɫ���� 1�ֽ�
	UINT16 Alpha;//͸���� 1�ֽ�
}MYPALETTE;


class ZBitmap
{
private:
   BITMAPFILEHEADER  bh;
   BITMAPINFOHEADER bih;
   MYRGBCOLOR      *rgb;
   MYPALETTE   *palette;

public:
   ZBitmap();
   ZBitmap(string pathName);
   ~ZBitmap();
   
   BITMAPFILEHEADER getFileHeader();
   BITMAPINFOHEADER getInfoHeader();
   MYRGBCOLOR* getRGBColor();
   MYPALETTE *getPalette();

   void saveBitmap(string pathName);
   
};

#endif