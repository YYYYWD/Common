#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include "ellipse.h"


extern int ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,my_control;
void ellipsePoints(int init_x,int init_y,int x,int y, COLORREF color)
{
    setPixel(init_x+x, init_y+y,color);
    setPixel(init_x-x, init_y+y,color);
    setPixel(init_x+x, init_y-y,color);
    setPixel(init_x-x, init_y-y,color);

}
void Mid_ellipse(int x,int y, int a,int b,COLORREF cr)
{
    int init_x,init_y,d,dd1,dd2;
    init_x=x;
    init_y=y;
    x=0;
    y=b;
    d=b*b+a*a*(-b+0.25);
    dd1=b*b*(x+1);
    dd2=a*a*(y-0.5);
    ellipsePoints(init_x,init_y,x,y,cr);
    while(dd1<dd2)
    {
        if(d<=0)
        {
            d=d+b*b*(2*x+3);
            x++;
        }
        else
        {
            d=d+b*b*(2*x+3)+a*a*(-2*y+2);
            x++;
            y--;
        }
        dd1=b*b*(x+1);
        dd2=a*a*(y-0.5);
        ellipsePoints(init_x,init_y,x,y,cr);
    }
    d=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>=0)
    {
        if(d>0)
        {
            y--;
            d=d+a*a*(-2*y+3);
        }
        else
        {
            x++;
            y--;
            d=d+b*b*(2*x+2)+a*a*(-2*y+3);
        }
        ellipsePoints(init_x,init_y,x,y,cr);
    }
    
}

void input_ellipse()
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
    ellipse_xx0=count[0];
    ellipse_yy0=count[1];
    ellipse_a=count[2];
    ellipse_b=count[3];
}

void ellipse_test1()
{
    COLORREF cr1=RGB(255,255,255);
    COLORREF cr2=RGB(0,0,0);
    input_ellipse();
    Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
 while(1)
    {
        //lcd_put_ascii(50,50,'A',RGB((ellipse_xx0+ellipse_yy0)%256,ellipse_a%256,ellipse_b%256));
        int key=getchar();
        if(key==0x0F09)
        {
            my_control++;
            Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
            break;
        }
        else if(key==0x2E63)//(C)
        {
              Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
              input_ellipse();
              Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x4800)//上
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
             ellipse_yy0-=5;
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x5000)//下
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_yy0+=5;
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x4B00)//左
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_xx0-=5;
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
         else if(key==0x4D00)//右
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_xx0+=5;
            Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x1177)//a+
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_a+=5;
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x1F73)//a-
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_a-=5;
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x1E61)//b-
        {
             Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
            ellipse_b-=5;
              Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
         else if(key==0x2064)//b+
        {
               Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr2);
               ellipse_b+=5;
               Mid_ellipse(ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b,cr1);
        }
        else if(key==0x011B)
        {
            exit_graphic(0x143);//退出
            return;
        }
    }
}