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
	int T;
	while(cin>>T)
	{
		int X=1;
		while(T--)
		{
			ll A,B,C;
			cin>>A>>B>>C;
			if(A>C-B)
			{
				printf("Case #%d: true\n",X);	
			}
			else
			{
				printf("Case #%d: false\n",X);	
			}	
			X++;
		}
	
		
	}
	return 0;
}
