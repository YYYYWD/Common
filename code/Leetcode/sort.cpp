#include<iostream>
#include<math.h>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

void swap(vector<int>&a,int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void swap(int a[],int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void desplay(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
}
void desplay(int a[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
}
void select_sort(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
	{
		int min=i;
		for(int j=i+1;j<a.size();j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		} 
		swap(a,i,min);
	}
}
void maopao_sort(vector<int>&a)//冒泡排序 
{
	bool is_change=0;
	for(int i=a.size()-1;i>=0&&!is_change;i--)
	{
		is_change=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				is_change=0;
				swap(a,j,j+1);	
			}	
		}
	}
}
void charu_sort(vector<int>&a)//插入排序 
{
	for(int i=1;i<a.size();i++)
	{
		for(int j=i;j>0&&(a[j]<a[j-1]);j--)
		{
			swap(a,j,j-1);
				
		}
	}
}
int b[10];
void merge(int a[],int l,int m,int h) //归并排序 
{
	int i=l,j=m+1;
	for(int k=l;k<=h;k++)
	{
		b[k]=a[k]; //数组复制到辅助数组 
	}
	for(int k=l;k<=h;k++)
	{
		if(i>m)
			a[k]=b[j++];
		else if(j>h)
			a[k]=b[i++];
		else if(b[i]<=b[j])
		{
			a[k]=b[i++];
		}
		else
		{
			a[k]=b[j++];
		}
	}
}
//将一个大数组分成两个小数组去求解。
//因为每次都将问题对半分成两个子问题，这种对半分的算法复杂度一般为 O(NlogN)。
void merge_sort(int a[],int l ,int h)//自顶向下归并排序 
{
	if(h<=l)
		return ;
	int mid=l+(h-l)/2;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,h);
	merge(a,l,mid,h);
}


int partition(int a[],int l,int h)
{
	int i=l,j=h+1;
	int divide_num=a[l];
	while(1)
	{
		while((a[++i]<divide_num)&&i!=h);
		while((a[--j]>divide_num)&&j!=l);
		if(i>=j)
		{
			break;	
		}	
		swap(a,i,j);
	} 
	swap(a,l,j);
	return j;
}
void quick_sort(int a[],int l,int h)//当前的快排只是取最左边的第一个数作为划分点。 
{
	if(l>=h)
		return ;
	int j=partition(a,l,h);
	quick_sort(a,l,j-1);
	quick_sort(a,j+1,h);	
}

int main()
{
	int a[10]={3,4,1,2,7,9,10,8,6,5};
	desplay(a,10);
	cout<<endl;
	//select_sort(a);
	//merge_sort(a,0,9);
	quick_sort(a,0,9);
	desplay(a,10);
	return 0;
}
