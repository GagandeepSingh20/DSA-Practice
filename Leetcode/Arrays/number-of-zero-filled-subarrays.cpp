// """
// Problem Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/
// Problem Number: 2348
// Problem Name: Number of Zero-Filled Subarrays
// Difficulty: Medium
// Tags: Array, Math

// Problem Summary:
// Given an integer array nums, return the number of subarrays filled with 0.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example:
// Input: nums = [1,3,0,0,2,0,0,4]
// Output: 6
// Explanation:
// There are 4 subarrays filled with zeroes of length 1.
// There are 2 subarrays filled with zeroes of length 2.
// Total = 6.

// Approach:
// - Iterate through the array, keeping track of the current streak of consecutive zeroes.
// - For every zero encountered, increase `curr` by 1 and add it to the result `score`.
// - Reset `curr` to 0 whenever a non-zero element is found.
// - The cumulative count ensures subarrays of all lengths are included.

// Time Complexity: O(n)
// Space Complexity: O(1)
// """

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int curr = 0;
        long long score = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                curr = 0;  // reset streak
            } else {
                score += curr + 1;  // count new subarrays ending at this index
                curr++;
            }
        }
        return score;
    }
};
