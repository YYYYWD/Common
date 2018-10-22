/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.61%)
 * Total Accepted:    389.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    bool is_huiwen(string s,int begin,int end)
    {
        int i=begin;
        int j=end;
        while(i!=j)
        {
            if(s[i]!=s[j])
                return false;
            else
            {
                if(i+1==j)
            		break;
                i++;
                j--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        int max_begin=0;
        int max_end=0;
        int max_num=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(is_huiwen(s,i,j))
                {
                    if(j-i+1>max_num)
                    {
                        max_begin=i;
                        max_end=j;
                        max_num=j-i+1;
                    }
                }
            }
        }
        string re=ping_jie(s,max_begin,max_end);
        return re;
    }
    string ping_jie(string s,int begin,int end)
    {
        string re;
        for(int i=begin;i<=end;i++)
            re+=s[i];
        return re;
    }
};
