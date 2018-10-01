#ifndef _LINE_H
#define _LINE_H

#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>
#include "font_8x16.h"

#define ABS(a) ((a) >= 0 ? (a) : -(a))

void DDAline2(int x0,int y0,int x1,int y1,COLORREF cr);
void Bresenham(int x0,int y0,int x1,int y1,COLORREF cr);
void Mid_line(int x0,int y0,int x1,int y1,COLORREF cr);
void Mid_line1(int x0,int y0,int x1,int y1,COLORREF cr);
void Line_Midpoint(int x1, int y1, int x2, int y2, COLORREF color);
void input();
void Line_test1();//测试DDA
void Line_test2();//测试Bresenham
void Line_test3();//测试中点画法
//void control();
//void my_print(char c[],int length);
#endif /*_LINE_H*/