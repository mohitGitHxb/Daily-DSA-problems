#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int maxLength = 0;
        int numDeletions = 0;
        while(right < nums.size()) {
            if(nums[right] == 0) {
                numDeletions++;
            }
            while(numDeletions > 1) {
                if(nums[left] == 0) {
                    numDeletions--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left);
            right++;
        }
        return maxLength;
    }
};
