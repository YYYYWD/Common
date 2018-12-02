/*
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (48.07%)
 * Total Accepted:    174.5K
 * Total Submissions: 363K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *  * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 */
class Solution {
public:
   string intToRoman(int num) 
    {
        int I=0;//1
        int V=0;//5
        int X=0;//10
        int L=0;//50
        int C=0;//100
        int D=0;//500
        int M=0;//1000
        int count[4]={0};
        string str;
        for(int i=0;i<4;i++)
        {
            count[i]=num/pow(10,3-i);
            num=num-count[i]*pow(10,3-i);
        }
        if(count[0]!=0)
        {
            while(count[0]--)
                str+='M';
        }
        if(count[1]!=0)
        {
            if(count[1]==9)
            {
                str+="CM";
            }
            else if(count[1]==4)
            {
                str+="CD";
            }
            else if(count[1]>=5)
            {
                str+='D';
                count[1]=count[1]-5;
                while(count[1]--)
                    str+='C';
            }
            else 
            {
                while(count[1]--)
                    str+='C';
            }
        }
        if(count[2]!=0)
        {
            if(count[2]==9)
            {
                str+="XC";
            }
            else if(count[2]==4)
            {
                str+="XL";
            }
            else if(count[2]>=5)
            {
                str+='L';
                count[2]=count[2]-5;
                while(count[2]--)
                    str+='X';
            }
            else
            {
                while(count[2]--)
                    str+='X';
            }
        }
        if(count[3]!=0)
        {
            if(count[3]==9)
            {
                str+="IX";
            }
            else if(count[3]==4)
            {
                str+="IV";
            }
            else if(count[3]>=5)
            {
                str+='V';
                count[3]=count[3]-5;
                while(count[3]--)
                    str+='I';
            }
            else
            {
                while(count[3]--)
                    str+='I';
            }
        }
        return str;
}
};