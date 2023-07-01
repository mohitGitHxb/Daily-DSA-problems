#include <bits/stdc++.h>
using namespace std;

/*
*Problem*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

*Explanation*
    Create a vector cur of size W+1 to store the maximum values for each weight from 0 to W.

    Initialize the base case for the first item (val[0], wt[0]). Iterate from wt[0] to W, and calculate the maximum value for each weight by considering multiples of wt[0] until the weight limit is reached. Store the calculated values in the cur array.

    Iterate over the remaining items (from the second item to the Nth item).

    For each item, iterate over the possible weights (from 0 to W).

    Calculate the maximum value for the current subproblem (i, j) by considering two options:

    a. Option 1: Not taking the current item. Set notTake as the maximum value obtained by considering the previous item at weight j.

    b. Option 2: Taking the current item multiple times until the weight exceeds the capacity (W). Check if the weight of the current item (wt[i]) is less than or equal to the current weight (j). If true, calculate the maximum value (take) by adding the value of the current item (val[i]) with the maximum value obtained by considering the current item at weight (j - wt[i]).

    c. Choose the maximum value between the two options (notTake and take) and store it in the cur array at the current weight (j).

    Repeat steps 3-5 for all remaining items.

    Finally, the maximum value that can be achieved within the given weight limit (W) is stored in cur[W]. Return this value as the result.

The time complexity of the code is O(N*W), where N is the number of items and W is the given weight limit. The code iterates over N items and for each item, it iterates over W possible weights. The space complexity is O(W) as we only need to store the values for the current weight range.
 */

int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<int> cur(W + 1);
    for (int i = wt[0]; i <= W; i++)
    {
        cur[i] = ((int)i / wt[0]) * val[0];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + cur[j];
            int take = (wt[i] <= j) ? val[i] + cur[j - wt[i]] : -1e9;
            cur[j] = max(take, notTake);
        }
    }
    return cur[W];
}

int main()
{
    return 0;
}