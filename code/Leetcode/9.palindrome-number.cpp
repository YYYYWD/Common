/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (39.10%)
 * Total Accepted:    418.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
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
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else
        {
            if(x==reverse(x))
                return true;
            else    
                return false;
        }
    }
};
