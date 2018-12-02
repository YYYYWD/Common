/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.78%)
 * Total Accepted:    162.7K
 * Total Submissions: 1M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)
        {
            return INT_MAX;
        }
        bool sign=(dividend<0)^(divisor<0);
        long long ldividend=labs(dividend);
        long long ldivisor=labs(divisor);
        int result=0;
        while(ldividend>=ldivisor)
        {
            long long k=ldivisor;
            long long l=1;
            while(ldividend>=(k<<1))
            {
                k=k<<1;
                l=l<<1;
            }
            result+=l;
            ldividend-=k;
        }
        return sign?-result:result;
    }
};
