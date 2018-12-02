/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.64%)
 * Total Accepted:    297.2K
 * Total Submissions: 768.7K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    void dfs(vector<string>&list,string digits,string curr,int index,string table[])
{
    if(index==digits.length())
    {
        if(curr.length()!=0)list.push_back(curr);
        return;
    }
    string temp=table[digits[index]-'0'];
    for(int i=0;i<temp.length();i++)
    {
        string next=curr+temp[i];
        dfs(list,digits,next,index+1,table);
    }
    
}
    vector<string> letterCombinations(string digits) {
        vector<string>list;
        string table[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(list,digits,"",0,table);
        return list;
    }
   
};
