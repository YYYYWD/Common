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

 int maxSubArray(vector<int>& nums) {
        int dp[100000]={0};
        for(int i=0;i<nums.size();i++)
        {
            if(i-1<0)
            {
                dp[i]=nums[i];
            }
            else
            {
            if(dp[i-1]<0)
            {
                
                    dp[i]=nums[i];
            }
                
            else
                dp[i]=dp[i-1]+nums[i];
            }
            
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
        	cout<<dp[i]<<endl;
            if(ans<dp[i])
                ans=dp[i];
        }
        
        return ans;

    }
int main()
{
	vector<int>a;
	int aa[2]={-2,-1};
	for(int i=0;i<2;i++)
		a.push_back(aa[i]);
	cout<<maxSubArray(a)<<endl;
	return 0;
}
