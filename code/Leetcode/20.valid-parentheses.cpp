/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.87%)
 * Total Accepted:    433.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.length()==0)
            return true;
        stack<char>sta1;
        for(int i=0;i<s.length();i++)
        {
            if(sta1.empty())
            {
                sta1.push(s[i]);
               
            }
            else if((s[i]==')'&&sta1.top()=='(')||(s[i]==']'&&sta1.top()=='[')||(s[i]=='}'&&(sta1.top()=='{')))
            {
                sta1.pop();
            }
            else
            {
                sta1.push(s[i]);
            }
        }
        if(sta1.empty())
        {
            return true;
        }
        else    
            return false;
    }
};
