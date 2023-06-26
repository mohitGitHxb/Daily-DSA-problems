#include <bits/stdc++.h>
using namespace std;

/*
@Problem
find nCr 

Solution using dp and recursion

Recursion (gives TLE)


The function nCr takes two parameters, n and r, which represent the values of "n choose r" that need to be calculated.

The base case of the recursion is defined by checking if either r is 0 (no elements to choose) or n is equal to r (all elements are chosen). In either case, the function returns 1 since there is only one way to choose 0 elements or to choose all elements.

If the base case is not met, the function recursively calculates the binomial coefficient using the formula: nCr = (n-1)C(r-1) + (n-1)C(r). This formula represents the idea that to choose r elements from n elements, we can either include the first element and choose the remaining (r-1) elements from the remaining (n-1) elements, or exclude the first element and choose r elements from the remaining (n-1) elements.

The recursive calls continue until the base case is reached, and the function computes the value of nCr by summing the two recursive calls.

Finally, the result of nCr is returned, and in this specific implementation, it is taken modulo mod to handle large values and prevent overflow.

The code effectively calculates the binomial coefficient by breaking down the problem into smaller subproblems and combining their solutions. However, it should be noted that this implementation has an exponential time complexity of O(2^n) since it involves redundant calculations. To optimize the computation of binomial coefficients, dynamic programming or memoization techniques can be used to avoid recalculating the same values multiple times.

int nCr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return (nCr(n - 1, r - 1) + nCr(n - 1, r))%mod;
    }
}
Memoization (Overlapping sub-problems) T.C : O(n*r) S.C : O(n*r) + O(n)


The function solve takes three parameters: n, r, and dp. n and r represent the values of "n choose r" that need to be calculated, and dp is a 2D vector used for memoization.

The base case of the recursion is the same as in the previous code: if r is 0 (no elements to choose) or r is equal to n (all elements are chosen), the function returns 1.

Before performing any calculations, the code checks if the value of dp[n][r] is already computed and stored in the memoization table. If the value exists, it is directly returned from the table, avoiding redundant calculations.

If the value is not present in the memoization table, the code recursively calculates the binomial coefficient using the same formula as before: nCr = (n-1)C(r-1) + (n-1)C(r). The recursive calls to solve are made with n-1 and r-1 for the first term and n-1 and r for the second term.

The calculated value of nCr is stored in the memoization table dp for future use.

Finally, the calculated value of nCr is returned, and it is also stored in the memoization table for future reference.

The use of memoization optimizes the computation of binomial coefficients by storing previously calculated values in the table. This ensures that the same value is not recalculated multiple times, reducing the time complexity. The memoized version has a time complexity of O(n*r) since each distinct pair (n, r) is calculated only once and stored in the table.

// mod = 1e9+7 and dp[n+1][n+1] all elements are set to -1
int solve(int n, int r,vector<vector<int>> &dp){
        if(r == 0 || r == n){
            return 1;
        }
        if(dp[n][r] != -1)
            return dp[n][r];
        return dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
    }
Tabulation (Removing recursion stack space) T.C: O(n*r) S.C: O(n*r)


The function nCr takes two parameters: n and r, representing the values of "n choose r" that need to be calculated.

The code first checks if r is greater than n. If r is larger than n, it means it's not possible to choose r elements from a set of n elements, so the function returns 0.

The code initializes a 2D vector dp of size (n+1) x (n+1). This table will be used for tabulation, with dp[i][j] representing the value of "i choose j".

The code sets the base cases: dp[i][0] and dp[i][i] are initialized to 1, since choosing 0 or choosing all elements (i.e., i choose 0 or i choose i) always results in 1.

Using nested loops, the code fills the table dp iteratively. The outer loop runs from 1 to n, representing the values of i (the total number of elements). The inner loop runs from 1 to r, representing the values of j (the number of elements to be chosen).

For each i and j, the value of dp[i][j] is calculated by adding the two preceding values: dp[i-1][j-1] (the number of ways to choose j elements from the first i-1 elements) and dp[i-1][j] (the number of ways to choose j elements from the first i-1 elements without including the ith element).

After filling the entire table, the code returns dp[n][r] modulo mod, which represents the final value of "n choose r".

This tabulation approach avoids recursion and calculates the binomial coefficient in a bottom-up manner, starting from the base cases and gradually filling the table until the desired value is reached. The time complexity of this approach is O(n*r) since it requires nested loops to fill the entire table.

// mod = 1e9+7
 int nCr(int n, int r){
        // code here
        if(r>n)return 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r]%mod;

    }
Space Optimization over Tabulation (We don't need the whole table just two rows of length r would be enough)
T.C : O(n*r) S.C: O(r)


The function nCr takes two parameters: n and r, representing the values of "n choose r" that need to be calculated.

The code first checks if r is greater than n. If r is larger than n, it means it's not possible to choose r elements from a set of n elements, so the function returns 0.

The code initializes two vectors: prev and curr, each of size (r+1). These vectors will store the values of the binomial coefficient at the previous iteration and the current iteration, respectively.

The base cases are set as follows:

prev[0] and curr[0] are initialized to 1, representing the value of "n choose 0" (which is always 1).
If r is equal to n, prev[r] and curr[r] are also initialized to 1, representing the value of "n choose r" (which is also 1 in this case).

Using nested loops, the code iteratively calculates the values of the binomial coefficient. The outer loop runs from 1 to n, representing the values of i (the total number of elements). The inner loop runs from 1 to r, representing the values of j (the number of elements to be chosen).

For each i and j, the value of curr[j] is calculated by adding the two preceding values: prev[j - 1] (the number of ways to choose j elements from the first i-1 elements) and prev[j] (the number of ways to choose j elements from the first i-1 elements without including the ith element). The result is stored in curr[j] modulo mod to handle large values.

After calculating the values for the current iteration, the prev vector is updated with the values from curr to be used in the next iteration.

Once the loop completes, the code returns prev[r], which represents the final value of "n choose r".

This optimized tabulation approach avoids the need for a full 2D table and only uses two vectors to store the necessary values for the previous and current iterations. It reduces the space complexity to O(r), making it more efficient in terms of memory usage. The time complexity remains O(n*r) since it still requires nested loops to iterate through the values.


Watch Striver's DP series highly recommended :-)
 */
    int nCr(int n, int r){
        // code here
        int mod = 1e9 + 7;
        if (r > n)
            return 0;
        vector<int> prev(r+1),curr(r+1);
        prev[0] = curr[0] = 1;
        if(r == n){
            prev[r] = curr[r] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                curr[j] = (prev[j - 1] + prev[j])%mod;
            }
            prev = curr;
        }
        return prev[r];

    }
int main(int argc, char const *argv[])
{

    return 0;
}
