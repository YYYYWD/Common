#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include "Circle.h"

extern int cir_xx0,cir_yy0,cir_r,my_control;

void input_circle()
{
    int i;
    int count[3]={0};
    for(i=0;i<3;i++)
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
    cir_xx0=count[0];
    cir_yy0=count[1];
    cir_r=count[2];
    
}
void CirclePoints(int init_x,int init_y,int x,int y, COLORREF color)
{
    setPixel(init_x+x, init_y+y,color);
    setPixel(init_x-x, init_y+y,color);
    setPixel(init_x+x, init_y-y,color);
    setPixel(init_x-x, init_y-y,color);
    setPixel(init_x+y, init_y+x,color);
    setPixel(init_x-y, init_y+x,color);
    setPixel(init_x+y, init_y-x,color);
    setPixel(init_x-y, init_y-x,color);


 
}
void Mid_Circle(int x,int y, int r,COLORREF color)
{
  
   float d;
   int init_x,init_y;
   init_x=x;
   init_y=y;
   x=0; y=r; d=1.25-r;
   
   CirclePoints(init_x,init_y,x,y,color);
   while(x<=y)
    { 
        if(d<0)   d+=2*x+3;
        else  
         { d+=2*(x-y)+5; y--;}
        x++;
         CirclePoints(init_x,init_y,x,y,color);
    }
}
void Bresenham_Circle(int x,int y, int r,COLORREF color)
{
     int init_x,init_y;
   init_x=x;
   init_y=y;
    x=0;
    y=r;
    int d=2*(1-r);
    int d1,d2,temp;
    while(x<=y)
    {
         CirclePoints(init_x,init_y,x,y,color);
        if(d<0)
        {
            d1=2*(d+y)-1;
            if(d1<=0)
                temp=1;//取H点
            else
                temp=2;//取D点
        }
        else if(d>0)
        {
            d2=2*(d-x)-1;
            if(d2<0)
                temp=2;//取D点
            else
                temp=3;//取V点
        }
        else
            temp=2;
        switch(temp)
        {
            case 1:
                x++;
                d+=2*x+1;
                break;
            case 2:
                x++;
                y--;
                d+=2*(x-y+1);
                break;
            case 3:
                y--;
                d+=(-2*y)+1;
        }
    }
}

void Circle_test1()
{
 while(1)
    {
        int key=getchar();
         if(key==0x0F09)
        {
            my_control++;
            Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
            break;
        }
        else if(key==0x2E63)//(C)
        {
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
               input_circle();
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
        }
        else if(key==0x4800)//上
        {
            Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
            cir_yy0-=5;
            Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x5000)//下
        {
                Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                  cir_yy0+=5;
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x4B00)//左
        {
          Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                   cir_xx0-=5;
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
         else if(key==0x4D00)//右
        {
           Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
               cir_xx0+=5;
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x1177)//R++
        {
         Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                cir_r+=2;
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x1F73)//R--
        {
                Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                cir_r-=2;
               Mid_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
       
        
    }
}
void Circle_test2()
{
while(1)
    {
        int key=getchar();
         if(key==0x0F09)
        {
            my_control++;
            Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
            break;
        }
        else if(key==0x2E63)//(C)
        {
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
               input_circle();
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
        }
        else if(key==0x4800)//上
        {
            Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
            cir_yy0-=5;
            Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x5000)//下
        {
                Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                  cir_yy0+=5;
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x4B00)//左
        {
          Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                   cir_xx0-=5;
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
         else if(key==0x4D00)//右
        {
           Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
               cir_xx0+=5;
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x1177)//R++
        {
         Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                cir_r+=2;
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
        else if(key==0x1F73)//R--
        {
                Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB(0,0,0));
                cir_r-=2;
               Bresenham_Circle(cir_xx0,cir_yy0,cir_r,RGB((cir_xx0+cir_yy0)%256,cir_yy0%256,cir_yy0%256));
       
        }
       
        
    }


}