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

//Ѱ������һ������target������
int binary(int nums[],int target,int length)
{
	int left=0;
	int right=length-1;
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(nums[mid]==target)return mid;
		else if(nums[mid]<target)left=mid+1;
		else
			right=mid;
	}
	if(left==target)
		return left;
	else
		return -1;
} 

//���½� �����ص��ǵ�һ������target������ 
int lower_binary(int nums[],int target,int length) 
{
	int left=0;
	int right=length-1;
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(nums[mid]<target)
			left=mid+1;
		else
			right=mid; //nums[mid]<=target rightһֱ����߿� 
	}
	if(nums[left]==target)
		return left; //���ص��ǵ�һ������target������ 
		//return left-1  //���ص��ǵ�һ��С��target������ 
	else
		return -1;
}
//���Ͻ� ,���ص��ǵ�һ������target��λ��
int up_binary(int nums[],int target,int length) 
{
	int left=0;
	int right=length-1;
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(nums[mid]<=target)
			left=mid+1;
		else
			right=mid;
	}
	if((right-1)>=0&&nums[right-1]==target)
		return right;//���ص��ǵ�һ������target��λ��
		//return right-1; //���ص������һ������target��λ��
	else
		return -1;
	
}
int main()
{
	int a[]={1,1,1,1,1,1,1,2};
	cout<<up_binary(a,1,8)<<endl;
}

