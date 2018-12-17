#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include "Fill.h"
#include "Line.h"
#include "My_Edge.h"

//struct Point point_array1[5]={{0,0},{50,50},{143,0},{98,120},{10,150}};
int count[20]={0};
int array_length0;
int array1_length;
//struct Point point_array1[5]={{0,0},{500,200},{500,500},{0,500}};//24968
struct Point point_array1[20];//={{0,0},{140,0},{140,140},{0,140}};
int graph1[805][605];
extern long long int number,my_control;
void change_DDAline(int x0,int y0,int x1,int y1,int cr)
{
   
    float increx, increy, x, y;
	int steps, i;
	if (ABS(y1 - y0) >= ABS(x1 - x0))
		steps = ABS(y1 - y0);
	else
		steps = ABS(x1 - x0);
	increx = (float)(x1 - x0) / steps;
	increy = (float)(y1 - y0) / steps;
	x = x0;
	y = y0;
    i=0;
	for (i = 0; i < steps; i++)
	{
		graph1[(int)x][(int)y]=cr;
        setPixel(x, y,RGB(255,0,0));
		x += increx;
		y += increy;
       
	}
}

void init()
{
    number=0;
    int i,j;
    array1_length=array_length0/2;
    for(i=0;i<805;i++)
    {
        for(j=0;j<605;j++)
        {
            graph1[i][j]=0;
        }
    }
    for(i=0;i<array1_length;i++)
    {
       change_DDAline(point_array1[i%array1_length].x,point_array1[i%array1_length].y,point_array1[(i+1)%array1_length].x,point_array1[(i+1)%array1_length].y,1);
    }
}
int getpixel(int x,int y)
{
    return graph1[x][y];
}
void FloodFill4(int x,int y,int oldcolor,int newcolor)
{
   
}
void BoundaryFill4(int x,int y,int boundarycolor,int newcolor)//boundarycolor:1,newcolor:2
{
    
    int color=getpixel(x,y);
    number=number+1;
    printf("(%d,%d)---%ld\n",x,y,number);
    if(color!=newcolor&&color!=boundarycolor&&x>=0&&y>=0)
    {
        graph1[x][y]=2;
        setPixel(x,y,RGB(0,255,0));
        BoundaryFill4(x,y-1,boundarycolor,newcolor);
        BoundaryFill4(x,y+1,boundarycolor,newcolor);
        BoundaryFill4(x-1,y,boundarycolor,newcolor);
        BoundaryFill4(x+1,y,boundarycolor,newcolor);
    }
}

void input_Point()
{
    int i;
    array_length0=0;
    int ttt=0;
    for(ttt=0;ttt<20;ttt++)
    {
        count[ttt]=0;
    }
    int Is_con_input=1;
    while(array_length0<20&&Is_con_input)
    {
        int length=1;
        int number[5]={0};
        while(length<5)
        {
            int key=getchar();
            if(key==0x332C)//(,)
            {
                break;
            }
            else if(key==0x0231)//1
            {
                number[length]=1;
                length++;
            }
             else if(key==0x0332)//2
            {
                number[length]=2;
                length++;
            }
             else if(key==0x0433)//3
            {
                number[length]=3;
                length++;
            }
             else if(key==0x0534)//4
            {
                number[length]=4;
                length++;
            }
             else if(key==0x0635)//5
            {
                number[length]=5;
                length++;
            }
             else if(key==0x0736)//6
            {
                number[length]=6;
                length++;
            }
             else if(key==0x0837)//7
            {
                number[length]=7;
                length++;
            }
             else if(key==0x0938)//8
            {
                number[length]=8;
                length++;
            }
             else if(key==0x0A39)//9
            {
                number[length]=9;
                length++;
            }
             else if(key==0x0B30)//0
            {
                number[length]=0;
                length++;
            }
            else if(key==0x011B)//esc
            {
                Is_con_input=0;
                break;
            }

        }
        int j;
        for(j=1;j<=length-1;j++)
        {
            count[array_length0]+=pow(10,length-j-1)*number[j];
        }
        array_length0=array_length0+1;
    }
    int ii=0;
    for(i=0;i<array_length0;i=i+2)
    {
        point_array1[ii].x=count[i];
        point_array1[ii].y=count[i+1];
        ii++;
    }
}

void print_Point()
{
    printf("%d\n",array_length0/2);
    array1_length=sizeof(point_array1)/sizeof(point_array1[0]);
    int i=0;
    for(i=0;i<20;i++)
    {
        printf("%d ",count[i]);
    }
    for(i=0;i<array1_length;i++)
    {
        printf("(%d,%d)\n",point_array1[i].x,point_array1[i].y);
    }
}