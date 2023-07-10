#include <bits/stdc++.h>
using namespace std;
/*
*Problem link*
https://practice.geeksforgeeks.org/problems/edit-distance3702/1

*Explanation*
This code is an implementation of a recursive function that calculates the edit distance between two strings s and t using memoization. The edit distance, also known as the Levenshtein distance, is the minimum number of operations required to transform one string into the other, where an operation can be an insertion, deletion, or replacement of a character.

The function takes as input two indices i and j, which represent the current positions in strings s and t, respectively. It also takes as input the two strings s and t, and a 2D vector dp that is used to store the results of subproblems to avoid recomputing them.

The function first checks if either index is less than 0. If j is less than 0, it means that all characters in string t have been processed, so the remaining characters in string s must be deleted to transform it into string t. In this case, the function returns i + 1, which is the number of remaining characters in string s. Similarly, if i is less than 0, it means that all characters in string s have been processed, so the remaining characters in string t must be inserted into string s to transform it into string t. In this case, the function returns j + 1, which is the number of remaining characters in string t.

If neither index is less than 0, the function checks if the result for this subproblem has already been computed and stored in the dp vector. If it has, the function returns the stored result. Otherwise, it continues to compute the result.

If the characters at indices i and j in strings s and t, respectively, are equal, no operation is required to transform one into the other at this position. In this case, the function makes a recursive call with indices i - 1 and j - 1, and stores and returns the result.

If the characters at indices i and j are not equal, an operation must be performed to transform one into the other. The function calculates the minimum cost of performing an insertion, deletion, or replacement by making recursive calls with updated indices and adding 1 to each result to account for the cost of the operation. It then stores and returns the minimum of these three values.

The time complexity of this algorithm is O(n * m), where n and m are the lengths of strings s and t respectively. This is because it computes and stores the result for each subproblem once, and there are n * m subproblems. The space complexity is also O(n * m), since it uses a 2D vector of size n * m to store the results of subproblems.
 */
int editDistance_memo(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        return i + 1;
    }
    if (i < 0)
    {
        return j + 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = editDistance_memo(i - 1, j - 1, s, t, dp);
    }

    int insertion = 1 + editDistance_memo(i, j - 1, s, t, dp);
    int deletion = 1 + editDistance_memo(i - 1, j, s, t, dp);
    int replacement = 1 + editDistance_memo(i - 1, j - 1, s, t, dp);

    return dp[i][j] = min(deletion, min(replacement, insertion));
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
