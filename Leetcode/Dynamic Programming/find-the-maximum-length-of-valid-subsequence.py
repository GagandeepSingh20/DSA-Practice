# Leetcode Problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
# Problem Number: 3202
# Problem Name: Find the Maximum Length of Valid Subsequence II
# Level: Medium
# Tags: Dynamic Programming, Modular Arithmetic, Arrays

"""
🧠 Problem Summary:
You're given an array `nums` and an integer `k`.
You want to find the length of the longest valid subsequence such that:
- For any two consecutive elements a, b in the subsequence:
  (a + b) % k == 0

📌 Example:
Input: nums = [1, 2, 3, 4, 5], k = 3
Output: 2
Explanation: Subsequence [1, 2] or [3, 3] satisfy the condition.

🛠️ Approach:
- Use dynamic programming with a 2D table `dp` of size k x k
- `dp[prev][curr]` represents the max length of subsequence ending with modulo `curr`
  where previous element had modulo `prev` and (prev + curr) % k == 0
- Transition: update `dp[prev][curr]` by `dp[curr][prev] + 1` for valid pairs

🧮 Time Complexity: O(n * k)
🧮 Space Complexity: O(k * k)
"""

from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for _ in range(k)]
        res = 0

        for num in nums:
            mod = num % k
            for prev in range(k):
                # Transition: if previous is `prev` and current is `mod`,
                # check if (prev + mod) % k == 0 is valid
                dp[prev][mod] = dp[mod][prev] + 1
            res = max(res, dp[prev][mod])

        return res
