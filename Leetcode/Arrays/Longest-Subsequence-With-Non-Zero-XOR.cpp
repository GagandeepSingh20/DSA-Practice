/**
 * Problem Link: https://leetcode.com/problems/3702
 * Problem Number: 3702
 * Problem Name: Longest Subsequence With Non-Zero XOR
 * Difficulty: Medium
 * Tags: Bit Manipulation, Array, XOR, Subsequence
 * 
 * Problem Summary:
 * Given an integer array, return the length of the longest subsequence 
 * such that its XOR is non-zero. If all elements are zero, return 0.
 * 
 * Example:
 * Input: nums = [1, 2, 3]
 * Output: 3
 * Explanation: XOR of all elements is 0^1^2^3=0 -> take all but one element.
 * 
 * Approach:
 * 1. XOR all elements of the array.
 * 2. If XOR != 0, the entire array can be taken, return size.
 * 3. If XOR == 0, check if there is any non-zero element.
 *    - If yes, remove one element to make XOR non-zero, return size - 1.
 *    - Otherwise, all zeros, return 0.
 * 
 * Time Complexity: O(n), where n is the size of nums.
 * Space Complexity: O(1)
 */


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        if (x != 0) return nums.size();
        for (int num : nums) {
            if (num != 0) return nums.size() - 1; 
        }
        return 0; 
    }
};
