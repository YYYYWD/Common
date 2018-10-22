#ifndef _MY_EDGE_H
#define _MY_EDGE_H

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


struct My_Edge
{
    
        int ymax;
        float x;
        float dx;
        struct My_Edge* next;
};
struct My_Edge *ET[1000];
struct My_Edge *AET;



#endif /*_MY_EDGE_H*/