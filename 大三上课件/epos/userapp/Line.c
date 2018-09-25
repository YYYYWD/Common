#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include"Line.h"

#define ABS(a) ((a) >= 0 ? (a) : -(a))


extern int xx0,yy0,xx1,yy1;
void DDAline2(int x0,int y0,int x1,int y1,COLORREF cr)
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
		setPixel(x, y,cr);
		x += increx;
		y += increy;
        printf("(%f,%f)\t",x,y);
	}
}

void Bresenham(int x0,int y0,int x1,int y1,COLORREF cr)
{
    int x,y,dx,dy,e,i,temp;
    int increx,increy;
    x=x0;
    y=y0;
    dx=ABS(x1-x0);
    dy=ABS(y1-y0);
    increx=(x1-x0)/dx;
    increy=(y1-y0)/dy;
    if(dx>dy)
    {
        e=-dx;
        temp=0;
    }
    else
    {
        e=-dy;
        temp=1;
    }
    if(temp==0)
    {
        for(i=0;i<dx;i++)
        {
            setPixel(x,y,cr);
            x=x+increx;
            e=e+2*dy;
            if(e>=0)
            {
                y=y+increy;
                e=e-2*dx;
            }
        }
    }
    else
    {
        for(i=0;i<dy;i++)
        {
            setPixel(x,y,cr);
            y=y+increy;
            e=e+2*dx;
            if(e>=0)
            {
                x=x+increx;
                e=e-2*dy;
            }
        }
    }
}
void Mid_line(int x0,int y0,int x1,int y1,COLORREF cr)
{
        int increx=ABS(x1-x0)/x1-x0;
        int increy=ABS(y1-x0)/y1-x0;
    if(ABS(x1-x0)<ABS(y1-y0))
    {
       
        int x,y,a,b,d,d1,d2;
        x=x0;
        y=y0;
        a=y0-y1;
        b=x1-x0;
        d=2*a+b;
        d1=2*b;
        d2=2*(a+b);
        setPixel(x,y,cr);
        while(x<x1)
        {
            if(d<0)
            {  y=y+increy;d=d+d1;}
            else
            {
                x=x+increx;
                y=y+increy;
                d=d+d2;
            }
            setPixel(x,y,cr);
        }
        return ;
    }
    int x,y,a,b,d,d1,d2;
    x=x0;
    y=y0;
    a=y0-y1;
    b=x1-x0;
    d=2*a+b;
    d1=2*a;
    d2=2*(a+b);
    setPixel(x,y,cr);
    while(x<x1)
    {
        if(d<0)
        {x=x+increx;y=y+increy;d=d+d2;}
        else
        {
            x=x+increx;
            d=d+d1;
        }
        setPixel(x,y,cr);
    }

}

void test1()
{
  while(1)
    {
        int key=getchar();
        if(key==0x2E63)//(C)
        {
              DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
              xx0=0;
              yy0=0;
              xx1=500;
              yy1=500;
              DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4800)//上
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x5000)//下
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4B00)//左
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x4D00)//右
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1177)//上
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1F73)//下
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1E61)//左
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x2064)//右
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x011B)
        {
            exit_graphic(0x143);//退出
            return;
        }
    }
}
void test2()
{
  while(1)
    {
        int key=getchar();
        if(key==0x2E63)//(C)
        {
              Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
              xx0=0;
              yy0=0;
              xx1=500;
              yy1=500;
              Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4800)//上
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x5000)//下
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4B00)//左
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x4D00)//右
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1177)//上
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1F73)//下
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1E61)//左
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x2064)//右
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        
    }
}
void test3()
{

}