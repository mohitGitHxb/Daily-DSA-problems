https://leetcode.com/problems/maximum-subarray/submissions/985413507/

TC O(N)
SC O(1)

int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxi = INT_MIN;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(sum, maxi);
            if(sum <0){
                sum =0;
            }
        }
        return maxi;
    }



It initializes two variables, sum and maxi. sum keeps track of the current sum of the subarray, and maxi stores the maximum sum found so far. maxi is initially set to the minimum possible integer value.
It iterates through each element of the nums array.
It adds the current element to the sum.
It compares the sum with maxi and updates maxi with the larger value.
If the sum becomes negative, it means including the current element in the subarray would decrease the overall sum. In this case, it resets the sum to zero, as starting a new subarray from the current position would yield a larger sum.
After iterating through all elements, the maxi variable will hold the maximum sum of a subarray.
Finally, it returns the maxi value.
