/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (51.59%)
 * Total Accepted:    306.6K
 * Total Submissions: 594.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void backtrace(vector<int>nums,vector<int>now,vector<vector<int> >&ans)
    {
        if(nums.size()==0)
            ans.push_back(now);
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                int n=nums[i];
                now.push_back(nums[i]);
                nums.erase(nums.begin()+i);//删除这个元素
                backtrace(nums,now,ans);
                nums.insert(nums.begin()+i, n);//把删除的元素加回来，不改变相对位置。
                now.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>now;
     
        backtrace(nums,now,ans);
        return ans;
    }
};
