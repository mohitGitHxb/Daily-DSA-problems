#include <bits/stdc++.h>
using namespace std;

/*
*Problem*
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

*Explanation using Tabulation [DP]*

 The function first initializes a 2D vector dp of size str.length() + 1 by txt.length() + 1 with all elements set to 0. This vector will be used to store the lengths of the LCSs of the prefixes of strings str and txt.

 Then, it enters a for loop that iterates from 1 to str.length(). Inside this loop, it enters another for loop that iterates from 1 to txt.length(). Inside this inner loop, it checks if characters at indices i-1 and j-1 in strings str and txt, respectively, are equal. If they are, it sets element [i][j] of vector dp to 1 plus element [i-1][j-1] of vector dp. If they are not equal, it sets element [i][j] of vector dp to 0.

 After both for loops, the function initializes an integer ans to a large negative value. It then enters another for loop that iterates through all rows of vector dp. Inside this loop, it sets integer ans to the maximum of its current value and the maximum element in row k of vector dp.

 After the last for loop, the function returns integer ans, which represents the length of the LCS of strings str and txt.

The key idea behind this code is that it uses a bottom-up dynamic programming approach to find the LCS of two strings. In each iteration of the inner for loop, it calculates the length of the LCS ending at indices i-1 and j-1 in strings str and txt, respectively. It does this by checking if characters at these indices are equal. If they are, it means that these characters are part of the LCS, so it includes them in the count. If they are not equal, it means that either character at index i-1 or character at index j-1 is not part of the LCS, so it sets element [i][j] of vector dp to 0.

The time complexity of this function is O(mn) where m and n are the lengths of strings str and txt, respectively. This is because it needs to fill in all elements of vector dp, which has size m x n. The space complexity is also O(mn) since it uses a 2D vector of size m x n to store intermediate results.

 */
int lcs_tabulation(string &str, string &txt)
{
    vector<vector<int>> dp(str.length() + 1, vector<int>(txt.length() + 1));
    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 1; j <= txt.length(); j++)
        {
            if (str[i - 1] == txt[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    int ans = -1e8;
    for (auto &k : dp)
    {
        ans = max(ans, *max_element(k.begin(), k.end()));
    }
    return ans;
}

int main()
{
    return 0;
}