#include <inttypes.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "graphics.h"
#include "My_Edge.h"
#include "Line.h"

/*struct Point point_array[11]={{566,970},{685,1020},{754,683},{985,768},
{1037,481},{1208,546},{1233,179},{1140,440},{951,386},{899,662},{668,562}};
*/
//x:800,y:600
struct Point point_array[5]={{20,20},{150,200},{800,20},{300,600},{20,500}};
void Scan_Line()
{
    int tt=0;
    for(tt=0;tt<5;tt++)
    {
        DDAline2(point_array[tt%5].x,point_array[tt%5].y,point_array[(tt+1)%5].x,
        point_array[(tt+1)%5].y,RGB(255,255,255));
    }
    int maxY=0;
    int length=11;
    int ii=0;
    for(ii=0;ii<length;ii++)
    {
        if(point_array[ii].y>maxY)
            maxY=point_array[ii].y;
    }
    struct My_Edge *pET[1200];//windowHeight
    for(ii=0;ii<maxY;ii++)
    {
        struct My_Edge *new1=(struct My_Edge*)malloc(sizeof(struct My_Edge));
        pET[ii]=&new1;
        pET[ii]->next=NULL;
    }
    struct My_Edge *new2=(struct My_Edge*)malloc(sizeof(struct My_Edge));
    AET=new2;
    AET->next=NULL;

    for(ii=0;ii<length;ii++)
    {
        int x0=point_array[(ii-1+length)%length].x;
        int y0=point_array[(ii-1+length)%length].y;
        int x1=point_array[ii].x;
        int y1=point_array[ii].y;
        int x2=point_array[(ii+1)%length].x;
        int y2=point_array[(ii+1)%length].y;
        int x3=point_array[(ii+2)%length].x;
        int y3=point_array[(ii+2)%length].y;
        if(y1==y2)
        {
            continue;
        }
        int ymin=y1>y2?y2:y1;
        int ymax=y1>y2?y1:y2;
        float x=y1>y2?x2:x1;
        float dx=(x1-x2)*1.0f/(y1-y2);
        if(((y1<y2)&&(y1>y0))||(y2<y1)&&(y2>y3))
        {
            ymin++;
            x+=dx;
        }
        struct My_Edge *new=(struct My_Edge*)malloc(sizeof(struct My_Edge));
        struct My_Edge *p=new;
        p->ymax=ymax;
        p->x=x;
        p->dx=dx;
        p->next=pET[ymin]->next;
        pET[ymin]->next=p;
    }
    for(ii=0;ii<maxY;ii++)
    {
        while(pET[ii]->next)
        {
           struct My_Edge*pInsert=pET[ii]->next;
            struct My_Edge*p=AET;
            while(p->next)
            {
                if(pInsert->x > p->next->x)
                {
                    p=p->next;
                    continue;
                }
                if(pInsert->x==p->next->x &&pInsert->dx>p->next->dx)
                {
                    p=p->next;
                    continue;
                }

                break;
            }
            pET[ii]->next=pInsert->next;
            pInsert->next=p->next;
            p->next=pInsert;
        }
        struct My_Edge* p=AET;
        while(p->next&&p->next->next)
        {
            int x;
            for(x=p->next->x;x<p->next->next->x;x++)
            {
                setPixel(x,ii,RGB(255,255,255));
            }
            p=p->next->next;
        }
        p=AET;
        while(p->next)
        {
            if(p->next->ymax==ii)
            {
                struct My_Edge*pDelete=p->next;
                p->next=pDelete->next;
                pDelete->next=NULL;
                free(pDelete);
            }
            else
            {
                p=p->next;
            }
        }
        p=AET;
        while (p->next)
        {
            p->next->x += p->next->dx;
            p = p->next;
        }
    }
}

