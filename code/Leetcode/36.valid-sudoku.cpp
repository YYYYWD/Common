/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (40.36%)
 * Total Accepted:    193.7K
 * Total Submissions: 479.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
     
        for(int i=0;i<9;i++)//行
        {
            int a[9]={0};
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                else
                {
                    if(a[(board[i][j]-'0')%9]==0)
                        a[(board[i][j]-'0')%9]++;
                    else
                        return false;
                }
            }
        }
        for(int i=0;i<9;i++)//列
        {
            int a[9]={0};
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.')
                {
                    continue;
                }
                else
                {
                    if(a[(board[j][i]-'0')%9]==0)
                        a[(board[j][i]-'0')%9]++;
                    else
                        return false;
                }
            }
        }
        for(int i=1;i<9;i+=3)
        {
            
            for(int j=1;j<9;j+=3)
            {
                int a[9]={0};
                for(int t1=i-1;t1<=i+1;t1++)
                {
                    for(int t2=j-1;t2<=j+1;t2++)
                    {
                        if(board[t1][t2]=='.')
                        {
                            continue;
                        }
                        else
                        {
                            if(a[(board[t1][t2]-'0')%9]==0)
                            {
                                a[(board[t1][t2]-'0')%9]++;
                            }
                            else
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};