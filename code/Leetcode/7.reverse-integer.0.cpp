/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.49%)
 * Total Accepted:    507.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
class Solution {
public:
   
    int reverse(int x) {
        long long int xx=0;
        int i=0;
        long long max = ((long long)1<<31)-1;
        long long min = 0 - (1 << 31);
        while(x)
        {
            xx=xx*10+x%10;
            x=x/10;
        }
        if(xx>max||xx<min)
        {
            return 0;
        }
        else
            return xx;
            
    }
};
