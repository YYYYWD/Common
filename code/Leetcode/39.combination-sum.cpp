/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (44.92%)
 * Total Accepted:    275.2K
 * Total Submissions: 612.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    void backTrace(vector<int>& candidates,vector<vector<int> >&res,vector<int>tmp,int target,int index)
    {
        if(target==0)
        {
            res.push_back(tmp);
            return;
        }
        else
        {
            for(int i=index;i<candidates.size();i++)
            {
                if(candidates[i]>target)
                {
                    return;
                }
                tmp.push_back(candidates[i]);
                backTrace(candidates,res,tmp,target-candidates[i],i);
                tmp.pop_back();
            }
        }

    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
       vector<vector<int> >ret;
       ret.clear();
       vector<int>tmp;
       tmp.clear();
       sort(candidates.begin(),candidates.end());
       backTrace(candidates,ret,tmp,target,0);
       return ret;
    }

};
