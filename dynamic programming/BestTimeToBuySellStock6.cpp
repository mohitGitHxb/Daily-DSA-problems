// PROBLEM: Leetcode 714
// Best Time to Buy and Sell Stock with Transaction Fee

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bottom Up Tabulation Method 
    // for finding the best time to buy and sell stocks

    // Time Compexity O(n)
    // Space Compexity O(1)
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur(2, 0), next(2, 0);       

        for(int i = n - 1; i >= 0; i--)
        {
            // cur[1] = I can buy a stock today
            // here, I have two choices
            // first, I decide not to buy the stock today, 
            //      so I wait for the next today with liberty of buying (next[1])
            // second, I decide to buy this stock,
            //      so I spend prices[i] to buy this stock and I cannot buy again untill I sell this one, so next[0]
            // finally taking the maximum of buying and not buying
            cur[1] = max(next[1], next[0] - prices[i]);  

            // cur[0] = I can sell stock today,
            // here I have two choices
            // first, I wish that I don't wish to sell the stock today
            //       so I wait for the next day with buy = 0 (next[0])
            // second, I wish to sell the stock today,
            //      which implies I will have the liberty to buy once again (next[1]) 
            //      I will get the current price of the stock (prices[i]) but I do have to pay the transaction fee 'fee'
            // lastly I take the maximum of sellng and not selling
            cur[0] = max(next[0], prices[i] + next[1] - fee);
            next = cur;
        }
        return next[1];
    }
};
 