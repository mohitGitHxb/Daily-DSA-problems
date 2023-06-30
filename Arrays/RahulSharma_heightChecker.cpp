#include <bits/stdc++.h>
using namespace std;
/* Problem link
 https://leetcode.com/problems/height-checker/

TC - O(N)
SC - O(N)

Approach -
A function was prepared with the name "heightChecker". It takes an array " Heights " as an argument. The array "heights" stores the current order in which the students are standing in the assembly. Another array of vector type was created (expected), which stores the expected order of students height in the assembly. The data of array "heights" was copied in "expected". And with the help of inbuilt sorting function, the array " expected " was sorted. A count variable was initialised with zero. Then both the arrays were compared using the while loop, for cases when the value of expected height doesn't match with the current order of height, the variable count was increased. Finally count was returned as the final  ans.

Code */

class Solution
{

public:
    int heightChecker(vector<int> &heights)
    {

        vector<int> expected(heights);

        int count = 0;

        sort(expected.begin(), expected.end());

        int i = 0;

        int j = 0;

        while (i < heights.size())
        {

            if (heights[i] != expected[j])
            {

                count++;
            }

            i++;

            j++;
        }

        return count;
    }
};

int main()
{
    return 0;
}