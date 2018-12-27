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

string str1[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
	string str[4];
	for(int i=0;i<4;i++)
		cin>>str[i];

	int t1=min(str[0].length(),str[1].length());
	string mytime;
	for(int i=0;i<t1;i++)
	{
		//cout<<"----"<<i<<endl;
		if((str[0][i]>='A'&&str[0][i]<='Z')&&mytime.length()==0&&str[0][i]==str[1][i])
			mytime+=str[0][i];
		else if(mytime.length()==1&&str[0][i]==str[1][i]) 
		//cout<<mytime<<endl;
			mytime+=str[0][i];
		else if(mytime.length()==2)
			break;
	}
	int t2=min(str[2].length(),str[3].length());
	
	int minute=0;
	for(int i=0;i<t2;i++)
	{
		//cout<<"----"<<i<<endl;
		//cout<<"**"<<str[2][i]<<endl;
		if((str[2][i]>='a'&&str[2][i]<='z')||(str[2][i]>='A'&&str[2][i]<='Z'))
		{
			if(str[2][i]==str[3][i])
		{
			//cout<<"****"<<str[2][i]<<endl;
			minute=i;
			break;	
		}
		}
		
	}
	//cout<<mytime<<"----"<<endl;
	int t11=mytime[0]-'A';
	cout<<str1[t11]<<" ";
	int t22=0;
	//cout<<mytime[1]<<endl;
	if(mytime[1]>='A')
		t22=mytime[1]-'A'+10;
	else
		t22=mytime[1]-'0';
	//cout<<"---"<<t22<<endl;
	if(t22<10)
		cout<<0<<t22<<":";
	else
		cout<<t22<<":";
	//cout<<"---"<<minute<<endl;
	if(minute<10)
		cout<<0<<minute;
	else
		cout<<minute;
	
	return 0;
}

