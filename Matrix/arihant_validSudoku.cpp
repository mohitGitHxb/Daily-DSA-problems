/*
@Problem 36.--- Valid Sudoku  url (https://leetcode.com/problems/valid-sudoku/)


T.C.-O(N^2) (All the elements need to be found so whole matrix is  traversed) 
S.C.-O(1);(All data structures have fixed length)


Description :
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

       1.Each row must contain the digits 1-9 without repetition.
       2.Each column must contain the digits 1-9 without repetition.
       3.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    1.A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    2.Only the filled cells need to be validated according to the mentioned rules.

Intuition:
   The Sudoku will be given as matrix (Array of Arrays)format,
   To check rows we need to check every inner array,
        i = index of row 
   To check columns we need to check every element placed at same positon in every inner array 
        j = index of column
   To check in the 3x3 sub boxes , there is a very exciting way :
        k=i/3*3+j/3;
        This value of k segregates the matrix in a very easy form:
         0  0  0 | 1  1  1 | 2  2  2
         0  0  0 | 1  1  1 | 2  2  2
         0  0  0 | 1  1  1 | 2  2  2
         --------+---------+---------
         3  3  3 | 4  4  4 | 5  5  5
         3  3  3 | 4  4  4 | 5  5  5
         3  3  3 | 4  4  4 | 5  5  5
         --------+----------+--------
         6  6  6 | 7  7  7 | 8  8  8
         6  6  6 | 7  7  7 | 8  8  8
         6  6  6 | 7  7  7 | 8  8  8


    Explanation :
     we define 3 9x9 matrix 
     used1: for checking respective  row for number 1-9
     used2: for checking respective  column for number 1-9
     used3: for checking respective  3x3 sub-boxes for 1-9
     
     
     Intialise every matrix with all values to be 0 as we have not found any at start.
     whenever we find any number 1-9, we check whether it already exists in used1,used2,used3 :
         if value is not zero in any of them then that number is duplicated and thus it will not be a valid sudoku;
         otherwise we change its value from 0 to 1 and go on to next element; 
*/

#include<bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1,;
                    int k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};

int main(){
    vector<vector<int>>board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]];
Solution obj = new Solution();
    bool result = obj.isValidSudoku(board);
  
    printf("%d",result);
    return 0;
}