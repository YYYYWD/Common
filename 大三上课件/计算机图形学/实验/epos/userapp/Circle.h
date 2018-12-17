#ifndef _CIRCLE_H
#define _CIRCLE_H

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

void CirclePoints(int init_x,int init_y,int x,int y, COLORREF cr);
void Mid_Circle(int x,int y, int r,COLORREF cr);
void Bresenham_Circle(int x,int y, int r,COLORREF color);
void input_circle();
void Circle_test1();
void Circle_test2();




#endif //_CIRCLE_H