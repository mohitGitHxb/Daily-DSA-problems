// c++ code
/*Problem
https://leetcode.com/problems/rotate-array

Time complexity: O(n)
Space complexity: O(1)

Intuition:
The goal is to rotate the elements of a vector nums to the right by a given number of positions k. The optimized approach aims to achieve this rotation in-place without using any additional arrays.

Approach:

The first step is to normalize the value of k by taking its modulus with the size of the nums vector. This ensures that k is within the valid range of indices and avoids unnecessary rotations.

The next step is to perform the rotation in three stages using the reverse function:

a. Reverse the entire vector nums using reverse(nums, 0, nums.size() - 1). This step effectively brings the last k elements to the front of the vector.

b. Reverse the first k elements of the vector nums using reverse(nums, 0, k - 1). After step (a), these are the elements that were originally at the end of the vector. Reversing them moves them back to their correct positions at the end of the vector.

c. Reverse the remaining elements of the vector nums (from index k to the last index) using reverse(nums, k, nums.size() - 1). This step ensures that the elements that were originally at the front of the vector are moved to their correct positions after the rotation.

The reverse function is a helper function that takes a vector nums and two indices l and r. It reverses the elements in nums between the indices l and r (inclusive). This function uses the two-pointer technique to swap elements from the two ends of the range until they meet in the middle.
*/
//Code

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};
