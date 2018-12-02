/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.25%)
 * Total Accepted:    407.5K
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
 * -4,-1,-1,0,1,2
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
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> >ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
    	//cout<<i<<endl;
    	int start=i+1;
    	int end=nums.size()-1;
    	int sum=-nums[i];
    	while(start<end)
		{
	    	if(sum==nums[start]+nums[end])
	    	{
	    		vector<int>ans1;
	    		ans1.push_back(nums[i]);
	    		ans1.push_back(nums[start]);
	    		ans1.push_back(nums[end]);
	    		ans.push_back(ans1);
	    		start++;
	    		end--;
	    		while(start<end&&nums[start]==nums[start-1])start++;
	    		while(start<end&&nums[end]==nums[end+1])end--;
			}
			else if(nums[start]+nums[end]>sum)
			{
				end--;
			}
			else
			{
				start++;
			}
			//cout<<i<<" "<<start<<" "<<end<<endl;
	}
			while(nums[i]==nums[i+1])i++;
    }
    return ans;
}
};
