class Solution {
public:
    bool isPossible(int sum, vector<int>& nums, int k) {
        int buckets = 1;
        int currSum = sum;
        for(int num : nums) {
            if(currSum - num < 0) {
                buckets++;
                currSum = sum;
            }
            currSum -= num;
        }
        return (buckets <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int res = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, nums, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};
