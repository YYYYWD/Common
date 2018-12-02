/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.09%)
 * Total Accepted:    344.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string com="";
        if(strs.size()==0)
            return com;
        int minlen = strs[0].size();
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()<minlen)
                minlen = strs[i].size();
        }
        int end=0;
        for(int i=0;i<minlen;i++)
        {
            int j;
            for(j=1;j<strs.size();j++)
            {
                if(strs[j][i]==strs[0][i])
                    continue;
                else    
                    break;
            }
            if(j==strs.size())
                end++;
            else
                break;
        }
        if(end==0)
            return "";
        else
            return strs[0].substr(0,end);
          
    }
};
