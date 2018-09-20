/*
 * vim: filetype=c:fenc=utf-8:ts=4:et:sw=4:sts=4
 */
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

#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define mode 1024*1024
extern void *tlsf_create_with_pool(void* mem, size_t bytes);
extern void *g_heap;

void test_sort1(void *pv);
void test_sort2(void *pv);
void test_sort3(void *pv);
void control(void*pv);

void my_swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
/**
 * GCC insists on __main
 *    http://gcc.gnu.org/onlinedocs/gccint/Collect2.html
 */

void __main()
{
    size_t heap_size = 32*1024*1024;
    void  *heap_base = mmap(NULL, heap_size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
	g_heap = tlsf_create_with_pool(heap_base, heap_size);
}
int msleep(const uint32_t msec)
{
	struct timespec ts={0,1000000*msec};
	return nanosleep(&ts, NULL);
}
/**
 * 第一个运行在用户模式的线程所执行的函数
 */
void DDAline1(int x0,int y0,int x1,int y1,COLORREF cr)
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
        printf("(%f,%f)\d",x,y);
	}
}
void Bresenham(int x0,int y0,int x1,int y1,COLORREF cr)
{
    if(ABS(x1-x0)<ABS(y1-y0))
    {
        int x,y,dx,dy,e,i;
        x=x0;
        y=y0;
    
        dx=ABS(x1-x0);
        dy=ABS(y1-y0);
        e=-dx;
        for(i=0;i<dy;i++)
        {
            setPixel(x,y,cr);
            y++;
            e=e+2*dx;
            if(e>=0)
            {
                x++;
                e=e-2*dy;
            }
        }
        return;
    }
   /* if(x1-x0<0)
    {
        my_swap(&x0,&x1);
        my_swap(&y0,&y1);
    }
    */
   
    int x,y,dx,dy,e,i;
    x=x0;
    y=y0;
  
    dx=x1-x0;
    dy=y1-y0;
      e=-dx;
    for(i=0;i<dx;i++)
    {
        setPixel(x,y,cr);
        x++;
        e=e+2*dy;
        if(e>=0)
        {
            y++;
            e=e-2*dx;
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


static int tid_foo1,tid_foo2,tid_foo3;   
unsigned char *stack_foo; 
unsigned int  stack_size = 1024*1024;   
//stack_foo = (unsigned char *) malloc(stack_size);    

int xx0,yy0,xx1,yy1;

void test1()
{
  while(1)
    {
        int key=getchar();
        if(key==0x2E63)//(C)
        {
              DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
              xx0=0;
              yy0=0;
              xx1=500;
              yy1=500;
              DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4800)//上
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1+5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x5000)//下
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy1=yy1-5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x4B00)//左
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1-5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x4D00)//右
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx1=xx1+5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1177)//上
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0+5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1F73)//下
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            yy0=yy0-5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
        else if(key==0x1E61)//左
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0-5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
        }
         else if(key==0x2064)//右
        {
            DDAline1(xx0,yy0,xx1,yy1,RGB(0,0,0));
            xx0=xx0+5;
            DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
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
void main(void *pv)
{
    xx0=0;
    yy0=0;
    xx1=500;
    yy1=500;
    printf("This is task foo with tid=%d\r\n", task_getid()); 
    
    init_graphic(0x143); //进入图形界面
    //DDAline1(xx0,yy0,xx1,yy1,RGB(255,255,255));
    //Bresenham(0,0,20,300,RGB(255,255,255));
    //test1();
    //test2();
    Mid_line(0,00,30,500,RGB(255,255,255));
    task_exit(0);
    
}

