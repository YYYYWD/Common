#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include "cut_line.h"

float XL;
float XR;
float YB;
float YT;

float Line_x01;
float Line_y01;
float Line_x02;
float Line_y02;

extern int my_control;
void REinput_line()
{
    line(Line_x01,Line_y01,Line_x02,Line_y02,RGB(0,0,0));
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
             else if(key==0x0635)//5d
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
    Line_x01=count[0];
    Line_y01=count[1];
    Line_x02=count[2];
    Line_y02=count[3];

}
void Input_Border()
{
    int i;
    int count[8]={0};
    for(i=0;i<8;i++)
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
    
    Line_x01=count[0];
    Line_y01=count[1];
    Line_x02=count[2];
    Line_y02=count[3];
    XL=count[4];
    XR=count[5];
    YB=count[6];
    YT=count[7];
    if(XL>XR)
    {
        float t=XL;
        XL=XR;
        XR=t;
    }
    if(YB>YT)
    {
        float t=YB;
        YB=YT;
        YT=t;
    }
}

int encode(float x, float y)
{
    int c=0;
    if(x<XL)c|=LEFT;
    if(x>XR)c|=RIGHT;
    if(y<YB)c|=BOTTOM;
    if(y>YT)c|=TOP;
    return c;
}
void init_CUT(COLORREF cr)
{
    
    line(XL,0,XL,800,cr);
    line(XR,0,XR,800,cr);
    line(0,YB,800,YB,cr);
    line(0,YT,800,YT,cr);
}
void CS_LineClip(float Line_x1,float Line_y1,float Line_x2,float Line_y2,COLORREF cr1)
{
    
    float x;
    float y;
    line(Line_x1,Line_y1,Line_x2,Line_y2,cr1);
    int code1,code2,code;
    code1=encode(Line_x1,Line_y1);
    code2=encode(Line_x2,Line_y2);
    printf("%d ----%d \n",code1,code2);
    while(code1!=0||code2!=0)
    {
        if((code1&code2)!=0)return;
        if(code1!=0)code=code1;
        else
            code=code2;
        if((LEFT&code)!=0)
        {
            x=XL;
            y=Line_y1+(Line_y2-Line_y1)*(XL-Line_x1)/(Line_x2-Line_x1);
        }
        else if((RIGHT&code)!=0)
        {
            x=XR;
            y=Line_y1+(Line_y2-Line_y1)*(XR-Line_x1)/(Line_x2-Line_x1);
        }
        else if((BOTTOM&code)!=0)
        {
            y=YB;
            x=Line_x1+(Line_x2-Line_x1)*(YB-Line_y1)/(Line_y2-Line_y1);
        }
        else if((TOP&code)!=0)
        {
            y=YT;
            x=Line_x1+(Line_x2-Line_x1)*(YT-Line_y1)/(Line_y2-Line_y1);
        }
        if(code==code1)
        {
            Line_x1=x;
            Line_y1=y;
            code1=encode(x,y);
        }
        else
        {
            Line_x2=x;
            Line_y2=y;
            code2=encode(x,y);
        }
        
    }
    line(Line_x1,Line_y1,Line_x2,Line_y2,RGB(0,255,0));
    //line(0,0,500,500,RGB(255,255,255));
}

void control_CUT()
{
    Input_Border();
    init_CUT(RGB(255,255,255));
    CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
    while(1)
    {
        int key=getchar();
         if(key==0x0F09)//tab
        {
            line(Line_x01,Line_y01,Line_x02,Line_y02,RGB(0,0,0));
            init_CUT(RGB(0,0,0));
            my_control++;
            break;
        }
        else if(key==0x2E63)//(C)
        {
          
            REinput_line();
            CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
        else if(key==0x4800)//上
        {
            init_CUT(RGB(0,0,0));
            YB-=5;
            init_CUT(RGB(255,255,255));
            line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
            CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
        else if(key==0x5000)//下
        {
            init_CUT(RGB(0,0,0));
            YB+=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
            CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
        else if(key==0x4B00)//左
        {
            init_CUT(RGB(0,0,0));
            XL-=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
       CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
         else if(key==0x4D00)//右
        {
            init_CUT(RGB(0,0,0));
            XL+=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
        CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }

        else if(key==0x1177)//上
        {
            init_CUT(RGB(0,0,0));
            YT-=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
            CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
        else if(key==0x1F73)//下
        {
            init_CUT(RGB(0,0,0));
            YT+=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
             CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
        else if(key==0x1E61)//左
        {
             init_CUT(RGB(0,0,0));
            XR-=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
         CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
         else if(key==0x2064)//右
        {
            init_CUT(RGB(0,0,0));
            XR+=5;
            init_CUT(RGB(255,255,255));
             line(Line_x01,Line_y01,Line_x01,Line_x02,RGB(0,0,0));
             CS_LineClip(Line_x01,Line_y01,Line_x02,Line_y02,RGB(255,0,0));
        }
    }
}



void swap_border(float *a,float *b)
{
    float t=*a;
    *a=*b;
    *b=t;
}
int IS_BIG(float a,float b)
{
    return a>b?1:0;
}