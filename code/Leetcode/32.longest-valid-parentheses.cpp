/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (24.26%)
 * Total Accepted:    157.1K
 * Total Submissions: 647.3K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int num=0;
        int max1=0;
        int max2=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('&&num>=0)
            {
                num++;
            }
            else if(s[i]==')'&&num>0)
            {
                num--;
                max1++;
                if(max1>max2)
                    max2=max1;
            }
            else 
            {
                max1=0;
                num=0;
            }
        }
        return max2;
    }
};
