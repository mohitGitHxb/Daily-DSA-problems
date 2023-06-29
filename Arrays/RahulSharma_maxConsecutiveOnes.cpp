#include<bits/stdc++.h>
using namespace std;
// Problem link

// https://leetcode.com/problems/max-consecutive-ones/

// TC - O(N) 
// SC - O(1) 

// Approach -
// A function was declared " FindMaxConsecutiveOnes " which takes an array "nums" as an argument. In this problem we have taken two variables " count " & " alt_count " , and initialised both of them with zero. Then a loop was initialised which increases the count of the variable " count " if element "1" is present inside the array. And then value of variable "alt_count" is updated, it takes the maximum value of the two variables present (alt_count  & count). If element "0" is present inside the array, the count is set to zero. Once all the iterations are executed, "alt_count" is returned as the final answer.

// Code

class Solution {

public:

int findMaxConsecutiveOnes(vector<int>& nums) {

        int count =0;

        int alt_count =0;

        for (int i=0;i<nums.size();i++){

if (nums[i]==1){

    count++;
}
alt_count = max(alt_count,count);

if (nums[i]==0){
    
    count =0;
}
        }
        return alt_count;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
