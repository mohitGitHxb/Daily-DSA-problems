/*
@Problem 807  --Max Increase TO Keep City Skyline url(https://leetcode.com/problems/max-increase-to-keep-city-skyline/)



Question:
   There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.
    A city's skyline is the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.


    Note:
    We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.

    Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.

Solution's Complexities:
  T.C. -O(N^2) where N is the size of matrix.
  S.C. -O(1) as all data structures are of fixed length.

Explanation:

    lets say the building heights are given as:
    let this be matrix A:
      3   0   8   4
      2   4   5   7
      9   2   6   3
      0   3   1   0

    To keep the outline of buildings the same as original we need to make sure that any element first doesnot exceed the minimum of the maximum values at its row and column.
    Outline from each direction will only be defined by the maximum heights as lower heights will be overshadowed.
    Check original of this example in the image.

        9    4    8    7   (maximum of each column)
       _|_|_|_
         3    0    8    4  | 8  ( maximum of row  1 )
         2    4    5    7  | 7  ( maximum of row  2 )
         9    2    6    3  | 9  ( maximum of row  3 )
         0    3    1    0  | 3  ( maximum of row  4 )


    Now we just make sure that to keep the outline same as before.
    Now A[0][0] =3 ;
    we make sure that it does not exceed the minimum of maximum values at 1st row and 1st column.
    Thus A[0][0] can be changed to min(max(row1),max(column1)) which is 8.
    how to get maximum value of row and columnn:
        To store Maximum values of a particular row or column we make two arrays of fixed length of n.
        Then we iterate the whole matrix


    Similarly the other values can be changed in this way.
    The end result will look like:

     8   4   8   7
     7   4   7   7
     9   4   8   7
     3   3   3   3
     The maximum of each row and column will remain the same as intended.



     Now we need to find the difference between values of original matrix and resultant matrix to get the total net increase in heights of all buildings

     total net increase in height = sum of difference of all elements of original matrix from resultant matrix which in this example equals to 35.

Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.(image attached)
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> col(n, 0), row(n, 0); /*TO store maximum values at each column and row */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res += min(row[i], col[j]) - grid[i][j];
        return res;
    }
};