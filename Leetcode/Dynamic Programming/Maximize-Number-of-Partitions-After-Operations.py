"""
🔗 Problem Link: https://leetcode.com/problems/maximize-number-of-partitions-after-operations/
🏷️ Problem No: 3003
📚 Problem Name: Maximize Number of Partitions After Operations
🧩 Difficulty: Hard
🧠 Tags: Bit Manipulation, Dynamic Programming, Prefix/Suffix Processing

📝 Problem Summary:
You are given a string `s` and an integer `k`.  
You can perform at most **one operation** — change a single character in `s` to any other lowercase letter.  
You then partition the string into groups such that:
- Each group contains **at most `k` distinct characters**, and
- The number of groups is maximized.

Return the **maximum number of groups** you can achieve after the operation.

📘 Example:
Input: s = "accca", k = 2  
Output: 3  
Explanation: Change the middle 'c' to 'b' → "acbca" → partitions ["ac"], ["bc"], ["a"]

💡 Approach:
1️⃣ Represent each character as a bitmask (`1 << (ord(c) - 97)`).
2️⃣ Build prefix and suffix information:
   - prefix_count[i] = number of partitions formed up to i.
   - prefix_mask[i] = active bitmask for the last group.
3️⃣ Similarly, compute suffix arrays from the end.
4️⃣ For each position `i` (possible modification point):
   - Simulate changing one character and combine prefix + suffix groups.
   - Use bitwise operations to efficiently compute distinct characters.
5️⃣ The result is the maximum partitions achievable.

🕒 Time Complexity: O(N)
🧮 Space Complexity: O(N)
"""

from typing import List

class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        bit_masks = [1 << (ord(c) - 97) for c in s]

        # Helper to build prefix/suffix partition info
        def build_prefix_info(arr: List[int]):
            prefix_count = [0]
            prefix_mask = [0]
            mask = 0
            groups = 0
            for bit in arr:
                mask |= bit
                if mask.bit_count() > k:
                    groups += 1
                    mask = bit
                prefix_count.append(groups)
                prefix_mask.append(mask)
            return prefix_count, prefix_mask

        # Build prefix and suffix info
        prefix_count, prefix_mask = build_prefix_info(bit_masks)
        suffix_count, suffix_mask = build_prefix_info(bit_masks[::-1])

        res = 0
        for i in range(n):
            left_groups = prefix_count[i]
            right_groups = suffix_count[-(i + 2)]
            left_mask = prefix_mask[i]
            right_mask = suffix_mask[-(i + 2)]
            combined_mask = left_mask | right_mask
            left_bits = left_mask.bit_count()
            right_bits = right_mask.bit_count()
            combined_bits = combined_mask.bit_count()

            # Evaluate possible partitions based on character modification
            if min(combined_bits + 1, 26) <= k:
                total = left_groups + right_groups + 1
            elif left_bits == right_bits == k and combined_bits < 26:
                total = left_groups + right_groups + 3
            else:
                total = left_groups + right_groups + 2

            res = max(res, total)

        return res
