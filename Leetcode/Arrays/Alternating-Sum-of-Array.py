"""
Problem Link: https://leetcode.com/problems/3701
Problem Number: 3701
Problem Name: Alternating Sum of Array
Difficulty: Easy
Tags: Array, Math, Simulation, Prefix Sum

Problem Summary:
Given an integer array nums, return the alternating sum of the array, 
where elements at even indices are added and elements at odd indices are subtracted.

Example:
Input: nums = [1, 2, 3, 4]
Output: -2
Explanation: 1 - 2 + 3 - 4 = -2

Approach:
1. Initialize sum = 0.
2. Iterate over the array indices.
3. If index is even, add the element to sum.
4. If index is odd, subtract the element from sum.
5. Return the sum.

Time Complexity: O(n), where n is the length of nums.
Space Complexity: O(1)
"""


class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
        sum = 0
        for i in range(len(nums)):
            if i % 2 == 0:
                sum += nums[i]
            else:
                sum -= nums[i]
        return sum
