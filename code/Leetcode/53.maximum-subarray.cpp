/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.99%)
 * Total Accepted:    417.5K
 * Total Submissions: 994.1K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
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
        	//cout<<dp[i]<<endl;
            if(ans<dp[i])
                ans=dp[i];
        }
        
        return ans;

    }
};
