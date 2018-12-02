/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.99%)
 * Total Accepted:    261.9K
 * Total Submissions: 513.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    void backtrade(vector<string>&ans,string ans1,int left,int right)
    {
        if(left==0&&right==0)
        {
            ans.push_back(ans1);
            return;
        }
        if(left>0)
        {
            backtrade(ans,ans1+"(",left-1,right);
        }
        if(right>left)
        {
            backtrade(ans,ans1+")",left,right-1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrade(res,"",n,n);
        return res;
    }
};
