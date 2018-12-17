/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (37.93%)
 * Total Accepted:    203.9K
 * Total Submissions: 537.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
            for(int i=0;i<nums.size();i++)   //表示每一次都选数组中的一个一个数当作第一个数
            {
                /* 和leetcode46 比起来 相对于重复的元素进行了处理！ */
                if(i>0&&nums[i]==nums[i-1])// 精华！！！ 和46题的对比！！！
                    continue;               //精华！！！
                int n=nums[i];
                now.push_back(nums[i]);
                nums.erase(nums.begin()+i);//删除这个元素
                backtrace(nums,now,ans);
                nums.insert(nums.begin()+i, n);//把删除的元素加回来，不改变相对位置。
                now.pop_back();
            }
        }
    }
      vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>now;
        sort(nums.begin(),nums.end());
        
      
        backtrace(nums,now,ans);
        return ans;
    }
};
