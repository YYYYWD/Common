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

typedef long long ll;


int main()
{
	int N;
	int A[1001]={0};
	int B[6]={0};
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
	}
	int n=1;
	float t=0;
	int n1=0;
	int n2=0;
	int n3=0;
	int n4=0;
	int n5=0;
	for(int i=1;i<=N;i++)
	{
		
		int temp=A[i]%5;
		
		switch (temp)
		{
		
			case 0:
				if(A[i]%2==0)
					B[1]+=A[i];
				break;
			case 1:
				B[2]+=n*A[i];
				n=n*(-1);
				break;
			case 2:
				B[3]++;
				break;
			case 3:
				B[4]+=A[i];
				t++;
				break;
			case 4:
				if(B[5]<A[i])
					B[5]=A[i];
				break;
		}
	}
	float B4;
	if(t!=0)
	{
		B4=B[4]/t;
		//cout<<t<<endl;
	}
	else
		B4=0;
	for(int i=1;i<=5;i++)
	{
		if(i==4&&i!=0)
		{
			if(B4!=0)
				printf("%.1f ",B4);
			else
				cout<<"N ";
		}
		else if(B[i]!=0&&i!=5)
			cout<<B[i]<<" ";
		else if(i==5&&B[i]!=0)
			cout<<B[i];
		else
			cout<<"N"<<" ";
	}
	return 0;
	
}
