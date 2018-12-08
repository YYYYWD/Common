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

void nixu(string& str,int start,int end)
{
	while(start<end)
	{
		char t=str[start];
		str[start]=str[end];
		str[end]=t;
		start++;
		end--;
	}
}
string all_nixu(string str)
{
	nixu(str,0,str.length()-1);
	cout<<str<<endl;
	for(int i=0;i<str.length();)
	{
		//cout<<i<<endl;
		if(str[i]!=' ')
		{
			//cout<<"---"<<endl;
			int start=i;
			int end=i;
			//cout<<"---"<<endl;
			while(++i&&i<str.length())
			{
				//cout<<i<<endl; 
				if(str[i]==' ')
				{
					end=i-1;
					break;
				}
			}
			
			nixu(str,start,end);
			
		}
		else
		{
			i++;
		}
	}
	return str;
	
}
int main()
{
	string str1="  i would love to miss you  ";
	
	cout<<all_nixu(str1)<<endl;
}
