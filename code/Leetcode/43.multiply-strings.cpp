/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (29.23%)
 * Total Accepted:    169.6K
 * Total Submissions: 580.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int count1[111]={0};
        int count2[111]={0};
        int ans[10000]={0};
        for(int i=0;i<max(num1.length(),num2.length());i++)
        {
            if(i<num1.length())
                count1[i]=num1[i]-'0';
            if(i<num2.length())
                count2[i]=num2[i]-'0';
        }
        for(int i=0;i<)

    }
};
