/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.10%)
 * Total Accepted:    607K
 * Total Submissions: 2.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count=0;
        if(s.length()==1)
            return 1;
        for(int i=0;i<s.length();i++)
        {
            int count=1;
            for(int j=s.length();j>i;i--)
            {
                if(s[i]!=s[j])
                {
                    continue;
                }
            }
            if(max_count<count)
            {
                max_count=count;
            }
        }
        return max_count;
    }
};
