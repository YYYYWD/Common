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


int prime( int n )
{
	float n_sqrt;
	if(n==2 || n==3) return 1;
	if(n%6!=1 && n%6!=5) return 0;
	n_sqrt=floor(sqrt((float)n));
	for(int i=5;i<=n_sqrt;i+=6)
	{
	    if(n%(i)==0 | n%(i+2)==0) return 0;
	}
        return 1;

}


int main()
{
	int M,N;
	cin>>M>>N;
	int T=0;
	int T1=0;
	for(int i=2;i<=10000;i++)
	{	
		
		if(prime(i))
		{
			T++;
			if(T>=M)
			{
				T1++;
				if(T1%10!=0&&T!=N)
					cout<<i<<" ";
				else if(T1%10!=0&&T==N)
					cout<<i;
				else 
					cout<<i<<endl;	
			}
			
		}
		if(T==N)
			break;
		
	}
	return 0;
}
