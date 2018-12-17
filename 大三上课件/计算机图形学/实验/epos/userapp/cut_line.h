#ifndef _CUT_LINE_H
#define _CUT_LINE_H

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

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8


int encode(float x, float y);
void CS_LineClip(float Line_x1,float Line_y1,float Line_x2,float Line_y2 ,COLORREF cr1);
void init_CUT(COLORREF cr);
void Input_Border();
void Input_Line();
void control_CUT();
void swap_border(float *a,float *b);
void REinput_line();
int IS_BIG(float a,float b);
#endif //_CUT_LINE_H