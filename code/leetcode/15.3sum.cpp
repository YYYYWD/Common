/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.27%)
 * Total Accepted:    407.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums,nums.size());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int sum=0;
                sum+=nums[i]+nums[j];
                int t=nums.size()-1;
                while(t>j)
                {
                    if(nums[t]+sum==0)
                    {
                        vector<int>ans1;
                        ans1.push_back(nums[i]);
                        ans1.push_back(nums[j]);
                        ans1.push_back(nums[t]);
                        
                    }

                }
            }
        }
    }
};
