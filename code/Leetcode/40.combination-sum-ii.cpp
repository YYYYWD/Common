/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (38.78%)
 * Total Accepted:    184.7K
 * Total Submissions: 476.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:

    void backtracing(vector<int>now,vector<int>& candidates, int target,vector<vector<int> >&ans,int index)
    {
        if(target==0)
        {
            ans.push_back(now);
        }
        else
        {
            for(int i=index;i<candidates.size();i++)
            {
                if(candidates[i]<=target)
                {
                    if(i>index&&candidates[i]==candidates[i-1])//精华！
                        continue;                   
                    now.push_back(candidates[i]);
                    backtracing(now,candidates,target-candidates[i],ans,i+1);//精华！
                    now.pop_back();
                }
                else
                    return;
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int> >ret;
       ret.clear();
       vector<int>tmp;
       tmp.clear();
       sort(candidates.begin(),candidates.end());
       backtracing(tmp,candidates,target,ret,0);
       return ret;
    }
};
