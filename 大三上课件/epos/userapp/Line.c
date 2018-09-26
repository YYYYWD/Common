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
     printf("------------------------\n");
    int x,y,dx,dy,e,i,temp;
    int increx,increy;
    x=x0;
    y=y0;
    dx=ABS(x1-x0);
    dy=ABS(y1-y0);
    //printf("(%d,%d)\n",dx,dy);
    if(dx==0)
    {
        increx=0;
    }
    else
    {
        increx=(x1-x0)/dx;
    }
     if(dy==0)
    {
        increy=0;
    }
    else
    {
        increy=(y1-y0)/dy;
    }
    //increx=(x1-x0)/dx;
    //increy=(y1-y0)/dy;
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
        {x++;y++;d=d+d2;}
        else
        {
            x=x++;
            d=d+d1;
        }
        setPixel(x,y,cr);
    }

}
void Mid_line1(int x0,int y0,int x1,int y1,COLORREF cr)
{
    int x,y,a,b,d,d1,d2,increx,increy,dx,dy;
    x=x0;
    y=y0;
    a=y0-y1;
    b=x1-x0;

    dx=ABS(x1-x0);
    dy=ABS(y1-y0);
    //printf("(%d,%d)\n",dx,dy);
    if(dx==0)
    {
        increx=0;
    }
    else
    {
        increx=(x1-x0)/dx;
    }
     if(dy==0)
    {
        increy=0;
    }
    else
    {
        increy=(y1-y0)/dy;
    }
    

    if(dx>=dy)
    {
        d=2*increx*a+increy*b;
        d1=2*increx*a;
        d2=2*a*increx+2*b*increy;
        setPixel(x,y,cr);
        while(x!=x1)
        {
            if(d<0)
            {
                x=x+increx;
                y=y+increy;
                d+=d2;
            }
            else
            {
                x=x+increx;
                d+=d1;
            }
            setPixel(x,y,cr);
        }
    }
    else
    {
        d=a*increx+2*b*increy;
        d1=2*b*increy;
        d2=2*increy*b+2*increx*a;
        setPixel(x,y,cr);
        while(y!=y1)
        {
            if(d<0)
            {
               y=y+increy;
               d+=d1;
            }
            else
            {
                x=x+increx;
                y=y+increy;
                d+=d2;
            }
            setPixel(x,y,cr);
        }
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
              input();
              DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4800)//上
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x5000)//下
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4B00)//左
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x4D00)//右
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1177)//上
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1F73)//下
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1E61)//左
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x2064)//右
        {
            DDAline2(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            DDAline2(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
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
              input();
              Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4800)//上
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x5000)//下
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4B00)//左
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x4D00)//右
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1177)//上
        {
           Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1F73)//下
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1E61)//左
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
           Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x2064)//右
        {
            Bresenham(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            Bresenham(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        
    }
}
void test3()
{
while(1)
    {
        int key=getchar();
        if(key==0x2E63)//(C)
        {
             Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
              input();
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4800)//上
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
          Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x5000)//下
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
           Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x4B00)//左
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x4D00)//右
        {Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1177)//上
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1F73)//下
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
           Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x1E61)//左
        {
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
         else if(key==0x2064)//右
        {
           Line_Midpoint(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            Line_Midpoint(xx0,yy0,xx1,yy1,RGB(xx0%255,yy0%255,xx1%255));
        }
        else if(key==0x011B)
        {
            exit_graphic(0x143);//退出
            return;
        }
    }
}


 
// 使用中点算法画任意斜率的直线（包括起始点，不包括终止点）
void Line_Midpoint(int x1, int y1, int x2, int y2, COLORREF color)
{
	int cx,cy;
    int x = x1, y = y1;
	int a = y1 - y2, b = x2 - x1;

    if(b>=0)
        cx=1;
    else
    {
        b=-b;
        cx=-1;
    }
    if(a<=0)
        cy=1;
    
    else
    {
        a=-a;
        cy=-1;
    }

	setPixel(x, y, color);
 
	int d, d1, d2;
	if (-a <= b)		// 斜率绝对值 <= 1
	{
		d = 2 * a + b;
		d1 = 2 * a;
		d2 = 2 * (a + b);
		while(x != x2)
		{
			if (d < 0)
				y += cy, d += d2;
			else
				d += d1;
			x += cx;
			setPixel(x, y, color);
		}
	}
	else				// 斜率绝对值 > 1
	{
		d = 2 * b + a; 
		d1 = 2 * b;
		d2 = 2 * (a + b);
		while(y != y2) 
		{ 
			if(d < 0)
				d += d1; 
			else 
				x += cx, d += d2; 
			y += cy; 
			setPixel(x, y, color);
		} 
	}
}
 

void input()
{
    int i;
    int count[4]={0};
    for(i=0;i<4;i++)
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
        }
        int j;
        for(j=1;j<=length-1;j++)
        {
            count[i]+=pow(10,length-j-1)*number[j];
        }
    }
    xx0=count[0];
    yy0=count[1];
    xx1=count[2];
    yy1=count[3];
}