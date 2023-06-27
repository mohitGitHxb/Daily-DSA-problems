#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1));

    // Initialize the base case for the first coin (coins[0])
    for (int target = 0; target <= amount; target++)
    {
        if (target % coins[0] == 0)
        {
            dp[0][target] = target / coins[0];
        }
        else
        {
            dp[0][target] = 1e9; // Set a large value to indicate an invalid state
        }
    }

    // Iterate over the remaining coins (coins[1] to coins[n-1])
    for (int i = 1; i < n; i++)
    {
        // Iterate over the possible amounts (0 to amount)
        for (int j = 0; j <= amount; j++)
        {
            // Calculate the minimum number of coins required for the current subproblem (i, j)

            // Option 1: Not taking the current coin
            int notTake = 0 + dp[i - 1][j];

            // Option 2: Taking the current coin if its value is less than or equal to the current amount (j)
            int take = 1e9;
            if (j >= coins[i])
            {
                take = 1 + dp[i][j - coins[i]];
            }

            // Choose the minimum number of coins between the two options and store it in the dp table
            dp[i][j] = min(take, notTake);
        }
    }

    // The minimum number of coins required to make the given amount is stored in the bottom-right cell of the dp table
    // If the value is still 1e9, it means it's not possible to make the amount with the given coins, so return -1
    return (dp.back()[amount] >= 1e9) ? -1 : dp.back()[amount];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
