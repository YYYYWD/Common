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


static int tid_foo1,tid_foo2,tid_foo3;   
unsigned char *stack_foo; 
unsigned int  stack_size = 1024*1024;   
//stack_foo = (unsigned char *) malloc(stack_size);    

int xx0,yy0,xx1,yy1;

void main(void *pv)
{
   
    //printf("This is task foo with tid=%d\r\n", task_getid()); 
    
    init_graphic(0x143); //进入图形界面
    input();
    //DDAline2(xx0,yy0,xx1,yy1,RGB(255,255,255));
    test3();
    //DDAline2(60,0,500,0,RGB(255,255,255));
    //Bresenham(60,0,500,0,RGB(255,255,255));
    //test1();
    //test2();
    //Mid_line1(500,0,0,400,RGB(255,255,255));
    //Mid_line1(60,0,500,0,RGB(255,255,255));
    //test2();
    printf("%d %d %d %d",xx0,yy0,xx1,yy1);
    task_exit(0);
    
}

