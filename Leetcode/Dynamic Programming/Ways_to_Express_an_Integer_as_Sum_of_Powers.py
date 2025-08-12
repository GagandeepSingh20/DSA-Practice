"""
Problem Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
Problem Number: 2787
Problem Name: Ways to Express an Integer as Sum of Powers
Difficulty: Medium
Tags: Dynamic Programming, Math, Combinatorics

Problem Summary:
Given two integers n and x, return the number of ways n can be expressed
as the sum of the x-th powers of unique positive integers, modulo 10^9 + 7.

Example:
Input: n = 10, x = 2
Output: 1
Explanation: 10 = 1^2 + 3^2 is the only way.

Approach:
1. Use 1D dynamic programming (subset sum style) to count combinations.
2. dp[j] = number of ways to make sum j.
3. Iterate through integers i from 1 upwards, compute val = i^x.
4. Update dp in reverse to avoid reusing numbers.
5. Answer is dp[n].

Time Complexity: O(n * k) where k is the largest integer with k^x <= n.
Space Complexity: O(n)
"""

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10**9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            val = i ** x
            if val > n:
                break

            for j in range(n, val - 1, -1):
                dp[j] = (dp[j] + dp[j - val]) % MOD

        return dp[n]
