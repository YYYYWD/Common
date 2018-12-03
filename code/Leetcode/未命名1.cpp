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

//寻找任意一个等于target的数字
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

//求下界 ，返回的是第一个等于target的数字 
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
			right=mid; //nums[mid]<=target right一直往左边靠 
	}
	if(nums[left]==target)
		return left; //返回的是第一个等于target的数字 
		//return left-1  //返回的是第一个小于target的数字 
	else
		return -1;
}
//求上界 ,返回的是第一个大于target的位置
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
		return right;//返回的是第一个大于target的位置
		//return right-1; //返回的是最后一个等于target的位置
	else
		return -1;
	
}
int main()
{
	int a[]={1,1,1,1,1,1,1,2};
	cout<<up_binary(a,1,8)<<endl;
}

