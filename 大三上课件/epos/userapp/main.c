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
#include "Line.h"
#include "Circle.h"
#include "ellipse.h"
#include "font_8x16.h"
#include "My_Edge.h"
#include <time.h>




#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define mode 1024*1024
extern void *tlsf_create_with_pool(void* mem, size_t bytes);
extern void *g_heap;



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



unsigned char *stack_foo; 
unsigned int  stack_size = 1024*1024;   
//stack_foo = (unsigned char *) malloc(stack_size);    

int xx0,yy0,xx1,yy1;
int cir_xx0,cir_yy0,cir_r;
int ellipse_xx0,ellipse_yy0,ellipse_a,ellipse_b;
int my_control=0;

void my_printf(char a[],int length,COLORREF cr,int xp,int yp)
{
    int i=0;
    for(i=0;i<length;i++)
    {
        lcd_put_ascii(500+i*8,50,a[i],cr);
    }
}
void control_Line()
{
    input_line();
    while(1)
    {
        
        if(my_control%3==0)
        {
            char c[]="------- D D A -------";
            my_printf(c,strlen(c),RGB(255,0,0),0,0);
            Line_test1();
        }
        else if(my_control%3==1)
        {
             char c[]="----- Bresenham -----";
            my_printf(c,strlen(c),RGB(0,255,0),0,0);
            Line_test2();
        }
        else
        {
            char c[]="----- MID__line -----";
            my_printf(c,strlen(c),RGB(0,0,255),0,0);
            Line_test3();
        }
    }
}

void control_Circle()
{
    //DDAline2(g_graphic_dev.XResolution/2-100,0,g_graphic_dev.XResolution/2-100,g_graphic_dev.YResolution,RGB(255,255,255));
    //DDAline2(0,g_graphic_dev.YResolution/2,g_graphic_dev.XResolution,g_graphic_dev.YResolution/2,RGB(255,255,255));
    input_circle();
    while(1)
    {
        
        if(my_control%3==0)
        {
            char c[]="------- Mid Circle  -------";
            my_printf(c,strlen(c),RGB(255,0,0),0,0);
            Circle_test1();
        }
        else if(my_control%3==1)
        {
            char c[]="----- Bresenham Circle-----";
            my_printf(c,strlen(c),RGB(0,255,0),0,0);
            Circle_test2();
        }
        else
        {
            char c[]="--------  Ellipse  --------";
            my_printf(c,strlen(c),RGB(0,0,255),0,0);
            ellipse_test1();
        }
        
    }
}
void main(void *pv)
{
   
    //printf("This is task foo with tid=%d\r\n", task_getid()); 
    
    //list_graphic_modes();
    init_graphic(0x143); //进入图形界面
    //input();
    //DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
    //control();
    //DDAline2(60,0,500,0,RGB(255,255,255));
    //Bresenham(60,0,500,0,RGB(255,255,255));
    //Line_test1();
    //Line_test2();
    //Mid_line1(500,0,0,400,RGB(255,255,255));
    //Mid_line1(60,0,500,0,RGB(255,255,255));
    //Line_test2();
    //printf("%d %d %d %d",xx0,yy0,xx1,yy1);
 
    //control_line();
    control_Circle();
    //Bresenham_Circle(0,0,50,RGB(255,255,255));
    //Mid_ellipse(500,500,80,60,RGB(255,255,255));
    //lcd_put_ascii(50,50,c[0],RGB(255,255,255));
    //ellipse_test1();
    task_exit(0);
    
}

