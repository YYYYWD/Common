#ifndef _FILL_H
#define _FILL_H

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


void init();
void change_DDAline(int x0,int y0,int x1,int y1,int cr);
int getpixel(int x,int y);
void FloodFill4(int x,int y,int oldcolor,int newcolor);
void BoundaryFill4(int x,int y,int boundarycolor,int newcolor);
void BoundaryFill8(int x,int y,int boundarycolor,int newcolor);
void input_Point();
void print_Point();
#endif /*_FILL_H*/