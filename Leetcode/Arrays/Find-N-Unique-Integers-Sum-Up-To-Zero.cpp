"""
Problem: Find N Unique Integers Sum up to Zero
LeetCode Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
Problem Number: 1304
Difficulty: Easy
Tags: Array, Math

Summary:
Given an integer n, return any array containing n unique integers such that they add up to 0.

Example:
Input: n = 5
Output: [-7,-1,1,3,4] (Any valid combination is acceptable)

Approach:
1. If n is odd, include 0 in the array to maintain balance.
2. Add pairs of integers (i, -i) for i from 1 to n/2.
3. This ensures all elements are unique and their sum is zero.

Time Complexity: O(n)
Space Complexity: O(n)
"""

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2 != 0) ans.push_back(0); // Add zero for odd n
        for (int i = 1; i <= n / 2; i++) {
            ans.push_back(-i);
            ans.push_back(i);
        }
        return ans;
    }
};
