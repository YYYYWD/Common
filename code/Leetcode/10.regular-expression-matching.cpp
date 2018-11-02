/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.44%)
 * Total Accepted:    240.5K
 * Total Submissions: 984.1K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        bool **dp=new bool*[lens+2];
        for(int i=0;i<lens+2;i++)
        {
            dp[i]=new bool[lenp+2];
        }
        for(int i=0;i<lens+2;i++)
        {
            for(int j=0;j<lenp+2;j++)
            {
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;

        for(int i=1;i<lenp;i++)
        {
            if(p[i]=='*'&&dp[0][i-1])
                dp[0][i+1]=true;
        }
        for(int i=0;i<lens;i++)
        {
            for(int j=0;j<lenp;j++)
            {
                if(s[i]==p[j]||p[j]=='.')
                    dp[i+1][j+1]=dp[i][j];
                else if(p[j]=='*')
                {
                    if(p[j-1]!=s[i]&&p[j-1]!='.')
                        dp[i+1][j+1]=dp[i+1][j-1];
                    else
                    {
                        dp[i+1][j+1]=(dp[i+1][j]//表示*匹配了1个字符
                        ||dp[i][j+1]//表示*匹配了多个字符
                        ||dp[i+1][j-1]);//表示*匹配了0个字符
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};
