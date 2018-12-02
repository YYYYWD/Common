/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    394.7K
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
    string longestPalindrome(string s) {
        int dp[1005][1005]={0};
        int length=s.size();
        int start=0;
        int end=0;
        int maxn=1;
        if(length<=1)
        {
            return s;
        }
        for(int i=0;i<length;i++)
        {
            dp[i][i]=1;
            if(i<length&&s[i]==s[i+1])// 两个连续相同的设置1
            {
                dp[i][i+1]=1;
                maxn=2;
                start=i;
            }
        }
        for(int len=3;len<=length;len++)  //设置长度从2开始
        {
            for(int i=0;i<=length-len;i++)
            {
                int j=len+i-1;
                if(dp[i+1][j-1]==1&&s[i]==s[j])
                {
                    dp[i][j]=1;
                    maxn=len;
                    start=i;
                }
            }
        }
        string str1= s.substr(start,maxn);
        return str1;


    }
};
