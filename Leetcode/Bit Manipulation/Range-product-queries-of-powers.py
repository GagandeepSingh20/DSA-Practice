"""
Problem Link: https://leetcode.com/problems/range-product-queries-of-powers/
Problem Number: 2438
Problem Name: Range Product Queries of Powers
Difficulty: Medium
Tags: Bit Manipulation, Prefix Product, Modular Arithmetic

Problem Summary:
You are given a positive integer `n` and an array of queries `queries`, where each query is [left, right].
- Consider the binary representation of `n`.
- Extract all powers of 2 corresponding to set bits in the binary representation.
- For each query, return the product of powers between indices `left` and `right` (inclusive), modulo 10^9 + 7.

Example:
Input:
n = 15
queries = [[0,1],[2,2],[0,3]]
Binary of 15 = 1111 (powers = [1, 2, 4, 8])
Output:
[2, 4, 64]

Approach:
1. Convert `n` to binary (LSB first) and record indices where bits are set.
2. Store powers of 2 for each set bit index.
3. For each query, multiply the powers from `left` to `right` using modulo 10^9+7.
4. Append results to the answer list.

Time Complexity: O(B + Q * R) 
    - B: bits in n
    - Q: number of queries
    - R: range length in queries
Space Complexity: O(B) 
    - For storing powers of set bits
"""

from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        power = []
        binary = []
        ans = []
        MOD = 10**9 + 7  # LeetCode requirement

        # Build binary representation (LSB first)
        while n >= 1:
            if n % 2 != 0:
                binary.append(1)
            else:
                binary.append(0)
            n //= 2

        # Store powers of 2 where binary[i] == 1
        for i in range(len(binary)):
            if binary[i] == 1:
                power.append(pow(2, i, MOD))  # store modded value

        # Answer queries
        for left, right in queries:
            prod = 1
            while left <= right:
                prod = (prod * power[left]) % MOD
                left += 1
            ans.append(prod)

        return ans
