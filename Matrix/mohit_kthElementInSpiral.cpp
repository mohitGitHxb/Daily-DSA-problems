#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
/* Problem
https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1
Explanation
The algorithm uses a counter to keep track of the number of elements visited. It starts by initializing variables top, left, right, and bottom representing the indices of the top, left, right, and bottom boundaries of the current spiral.

The algorithm uses a while loop that continues until the top index is less than or equal to the bottom index and the left index is less than or equal to the right index. This ensures that there are still elements to be visited in the spiral.

Inside the loop, the algorithm traverses the current boundary of the spiral in a clockwise manner:

    It iterates from left to right along the top row of the matrix. For each element, it checks if the counter is equal to k-1. If true, it returns the value of the matrix element at the top row and current column.
    It increments the top index to move to the next row.
    It iterates from top to bottom along the rightmost column of the matrix. For each element, it checks if the counter is equal to k-1. If true, it returns the value of the matrix element at the current row and rightmost column.
    It decrements the right index to move to the previous column.
    It checks if the top index is less than or equal to the bottom index.
    It iterates from right to left along the bottom row of the matrix. For each element, it checks if the counter is equal to k-1. If true, it returns the value of the matrix element at the bottom row and current column.
    It decrements the bottom index to move to the previous row.
    It checks if the left index is less than or equal to the right index.
    It iterates from bottom to top along the leftmost column of the matrix. For each element, it checks if the counter is equal to k-1. If true, it returns the value of the matrix element at the current row and leftmost column.
    It increments the left index to move to the next column.

After the while loop finishes, if no kth element is found, the function will return -1 (assuming -1 is not a valid element in the matrix).

The time complexity of this algorithm is O(n * m) since it iterates over all the elements in the matrix. The space complexity is O(1) as it uses only a constant amount of additional space. */

    int findK(int mat[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int counter = 0;
 		int top = 0,left = 0,right = m - 1,bottom = n - 1;
 		while(top <= bottom && left <= right){
 		    for(int i = left; i <= right; i++){
 		        if(counter == k-1)
 		            return mat[top][i];
 		        counter++;
 		    }
 		    top++;
 		    for(int i = top; i <= bottom; i++){
 		        if(counter == k-1)
 		            return mat[i][right];
 		        counter++;
 		    }
 		    right--;
 		    if(left <= right){
 		    for(int i = right; i >= left; i--){
 		        if(counter == k-1)
 		            return mat[bottom][i];
 		        counter++;
 		        }
 		        bottom--;
 		    }
 		    if(top <= bottom)
 		    {
 		    for(int i = bottom; i >= top; i--){
 		        if(counter == k-1)
 		            return mat[i][left];
 		        counter++;
 		    }
 		        left++;
 		    }
 		    
 		}
 		
    }
int main(){
    return 0;
}