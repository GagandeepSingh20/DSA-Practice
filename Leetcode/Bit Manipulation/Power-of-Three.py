"""
Problem Link: https://leetcode.com/problems/power-of-three/
Problem Number: 326
Problem Name: Power of Three
Difficulty: Easy
Tags: Math, Recursion

Problem Summary:
Given an integer n, return True if it is a power of three, otherwise return False.
An integer n is a power of three if there exists an integer x such that n == 3^x.

Example:
Input: n = 27
Output: True
Explanation: 27 = 3^3

Input: n = 0
Output: False

Approach:
1. If n <= 0, return False.
2. Keep dividing n by 3 while it is divisible by 3.
3. If the final result is 1, n is a power of three.

Time Complexity: O(log₃ n)
Space Complexity: O(1)
"""

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        while n % 3 == 0:
            n //= 3
        return n == 1
