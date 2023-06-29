#include <bits/stdc++.h>
using namespace std;

/*
@ PRoblem
PRATA - Roti Prata
no tags

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.
Input

The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.
Output

Print an integer which tells the number of minutes needed to get the order done.
Example

Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1


@ Explanation

This code is for solving the "Roti Prata" problem, where there are multiple cooks who can make rotis (a type of Indian bread), and the goal is to minimize the time required to prepare a certain number of rotis.

The `isFeasible` function checks if it is feasible to prepare the required number of rotis within a given time limit (`mid`). It iterates through each cook and calculates the total time taken by that cook to prepare the required number of rotis. The loop continues until the total time exceeds the given time limit. The function also keeps track of the total number of rotis prepared (`prata`) and checks if it reaches or exceeds the required number (`k`). If it does, it returns `true`, indicating that it is feasible to prepare the required number of rotis within the given time limit.

The `minimumTime` function performs a binary search between `low` and `high` time limits to find the minimum feasible time required to prepare the given number of rotis. It repeatedly calls the `isFeasible` function with the mid-time limit and adjusts the low and high values based on whether the feasibility condition is met or not. The function returns the final `ans`, which represents the minimum time required to prepare the rotis.

The time complexity of this code is O(N log M), where N is the number of cooks and M is the maximum time limit (10e8 in this case). This is because the binary search performs log M iterations, and within each iteration, the `isFeasible` function iterates through the cooks, taking O(N) time. Therefore, the overall time complexity is dominated by the binary search.

The space complexity is O(1) because the code uses a constant amount of extra space regardless of the input size.
 */
class RotiPrata
{
private:
public:
    bool isFeasible(vector<int> &cooks, unsigned int mid, int k)
    {
        unsigned int time = 0;
        unsigned int prata = 0;
        for (int i = 0; i < cooks.size(); i++)
        {
            time = cooks[i];
            int j = 2;
            while (time <= mid)
            {
                prata++;
                time += (cooks[i] * j);
                j++;
            }
            if (prata >= k)
            {
                return true;
            }
        }
        return false;
    }
    int minimumTime(vector<int> &cooks, int k)
    {
        unsigned int low = 0;
        unsigned int high = 10e8;
        unsigned int ans = 0;
        while (low <= high)
        {
            unsigned int mid = (low + high) / 2;
            if (isFeasible(cooks, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
