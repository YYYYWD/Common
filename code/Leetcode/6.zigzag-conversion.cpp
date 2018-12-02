/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (28.95%)
 * Total Accepted:    247.9K
 * Total Submissions: 856.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *          PAHNAPLSIIGYYIR
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 *           PINALSIGYAHRPP
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
   /*string convert(string s, int numRows) {
        char map[1005][1005]={};
        int temp=0;
        int flag=0;
        int col=1;
        int row=1;
		for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++)
            {
                map[i][j]=' ';
                
            }
        }
        for(int i=1;;)
        {
            int j=1;
            for(j=1;j<=numRows;j++)
            {
                map[j][i]=s[temp++];
                if(temp==s.size())
                {
                    flag=1;
                    col=i;
                    row=j;
                    break;
                }
                //cout<<"-"<<"("<<j<<","<<i<<")"<<endl; 
            }
            if(flag)
                break;
            j--;
            while(temp!=s.size()&&(j!=1))
            {
            	j=j-1;
            	i=i+1;
            	if(j==1)
            		break;
                map[j][i]=s[temp++];
                
                //cout<<"--"<<"("<<j<<","<<i<<")"<<endl; 
            }
            if(temp==s.size())
            {
                col=i;
                row=j;
                break;
            }
           
        }
        string  str1;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++)
            {
                if(map[i][j]!=' ')
                {
                    str1+=map[i][j];
                    //cout<<map[i][j];
                }
                
            }
            //cout<<endl;
        }
        
        return str1;
    }*/
        string convert(string s, int numRows) 
    {
        int mid=2*(numRows-1);
        string str1;
        int temp=s.size();
        int number1=0;
        int number2=0;
        int number3=0;
        if(temp<=numRows||numRows==1)
        	return s;
        for( int i=0;i<numRows;i++)
        {
        	str1+=s[i];
            number1=mid-i*2;
            if(i==numRows-1)
            	number1=mid;
            number2=number1+i;
            //cout<<str1<<endl;
            while(number2<=temp-1)
            {
            	//cout<<"-"<<"("<<i<<","<<number2<<")"<<endl; 
                str1+=s[number2];
                //cout<<str1<<endl;
                if(number1!=mid)
                	number1=mid-number1;
                number2=number2+number1;
                //cout<<"---"<<"("<<i<<","<<number2<<")"<<endl; 
            }
            //cout<<str1<<endl;
        }
        return str1;
    }

};
