#include <bits/stdc++.h>
using namespace std;

/*
@ problem link
https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1

@ Explanation
    Check if k is greater than the length of str. If it is, then there cannot be any matching prefixes, so return 0.
    Extract the substring ks from str starting from index 0 and of length k. This represents the k-length prefix of str.
    Sort the array of strings arr[] in lexicographical order. This step is performed to simplify the subsequent comparisons.
    Initialize a variable count to 0, which will store the count of matching strings.
    Iterate over each string in the array arr[].
        Check if the length of the current string is greater than or equal to the length of ks.
        Also, check if the last character of ks matches with the character at index ks.length()-1 of the current string. This ensures that the k-length prefix of the current string has the potential to match with ks.
        If both conditions are satisfied, extract the substring ms of length k from the current string.
        Compare ks with ms. If they are equal, increment the count as it indicates a match.
    Return the final count.

The code checks the length and the last character of the k-length prefix of each string in arr[] to determine if it matches with the corresponding prefix in str. By comparing and counting the matches, it provides the desired count of matching strings.

O(NlogN) T.C || O(1) S.C

Can be optimized using Tries 
 */
int klengthpref(string arr[], int n, int k, string str)
{
    if (k > str.length())
        return 0;
    string ks = str.substr(0, k);
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].length() >= ks.length() && ks.back() == arr[i][ks.length() - 1])
        {
            string ms = arr[i].substr(0, k);
            if (ks == ms)
                count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}