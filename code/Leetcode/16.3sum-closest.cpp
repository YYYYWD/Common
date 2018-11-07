/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (32.89%)
 * Total Accepted:    210.4K
 * Total Submissions: 639.8K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
   
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sub_target=INT_MAX;
        int ret=INT_MAX;
         //cout<<"sub_target:"<<sub_target<<endl;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int ans1=nums[i]+nums[j];
                int left=j+1;
                int right=nums.size()-1;
				//cout<<ans1<<endl;
                while(left<=right)
                {
                    int t=(left+right)/2;
                    //cout<<"t:"<<t<<endl;
                    if(ans1+nums[t]==target)
                        return target;
                    else if(ans1+nums[t]<target)
                    {
                        left=t+1;
                        if(abs(sub_target)>abs(target-ans1-nums[t]))
                        {
                        	sub_target=target-ans1-nums[t];
                        	ret=target-sub_target;
						}
                            
                        
                    }
                    else if(ans1+nums[t]>target)
                    {
                        right=t-1;
                        if(abs(sub_target)>abs(target-ans1-nums[t]))
                        {
                        	sub_target=target-ans1-nums[t];
                        	ret=target-sub_target;
						}
                    }
                }
                //cout<<"sub_target:"<<sub_target<<endl;
            }
        }
        return ret;
    }
};
