#ifndef _ELLIPSE_H
#define _ELLIPSE_H

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


void ellipsePoints(int init_x,int init_y,int x,int y, COLORREF cr);
void Mid_ellipse(int x,int y, int a,int b,COLORREF cr);

void input_ellipse();
void ellipse_test1();




#endif //_ELLIPSE_H