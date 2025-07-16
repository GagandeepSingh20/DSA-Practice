# Leetcode Problem: https://leetcode.com/problems/maximum-length-of-a-good-subsequence-ii/
# Problem Number: 3201
# Problem Name: Maximum Length of a Good Subsequence II
# Level: Medium
# Tags: Greedy, Array, Parity, DP-style

"""
🧠 Problem Summary:
You're given an integer list. A *good* subsequence is one of:
- Only even numbers
- Only odd numbers
- Alternating even-odd (starting with even)
- Alternating odd-even (starting with odd)

Return the maximum length of such a good subsequence.

📌 Example:
Input: nums = [3,2,5,4]
Output: 3
Explanation: One optimal subsequence is [3,2,5] (odd → even → odd)

🛠️ Approach:
- Count max possible subsequences of each type:
  1. All even (e)
  2. All odd (o)
  3. Alternating even→odd→even... (eo)
  4. Alternating odd→even→odd... (oe)

- Track current expected parity using XOR toggle

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
"""

from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        e, o, eo, oe = 0, 0, 0, 0
        req_eo, req_oe = 0, 1  # expected parity for alternating subsequences

        for x in nums:
            x %= 2  # reduce to parity: 0 for even, 1 for odd

            if x == 0:
                e += 1
            else:
                o += 1

            if x == req_eo:
                eo += 1
                req_eo ^= 1  # toggle between 0 and 1
            if x == req_oe:
                oe += 1
                req_oe ^= 1

        return max(e, o, eo, oe)
