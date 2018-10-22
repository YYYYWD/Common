/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.10%)
 * Total Accepted:    607.6K
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
        if(s.length()==0)
            return 0;
        set<char>max_s;
        int max_number=1;
        for(int i=0;i<s.length();i++)
        {
            max_s.clear();
            max_s.insert(s[i]);
            for(int j=i+1;j<s.length();j++)
            {
                max_s.insert(s[j]);
                if(max_s.size()!=j-i+1)
                {
                    break;
                }
            }
            if(max_s.size()>max_number)
                max_number=max_s.size();
        }
        return max_number;
    }
};
