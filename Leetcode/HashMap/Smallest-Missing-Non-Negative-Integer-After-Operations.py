"""
🔗 Problem Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
🏷️ Problem No: 2598
📚 Problem Name: Smallest Missing Non-Negative Integer After Operations
🧩 Difficulty: Medium
🧠 Tags: Hash Map, Math, Modular Arithmetic

📝 Problem Summary:
You are given an integer array `nums` and an integer `value`.
You can perform the following operation any number of times:
    - Pick any index `i` and add or subtract `value` from `nums[i]`.

After performing operations optimally, find the **smallest non-negative integer x** 
such that `x` is not present in the array.

📘 Example:
Input: nums = [1, -10, 7, 13, 6, 8], value = 5  
Output: 4  
Explanation:
Possible values mod 5 are: [1, 0, 2, 3, 1, 3]
Missing sequence starts at x = 4.

💡 Approach:
1️⃣ Compute the remainder of each element in nums modulo `value` (handling negatives safely).  
2️⃣ Count the frequency of each remainder using a dictionary.  
3️⃣ Start from x = 0, and repeatedly check if `x % value` is available:
    - If remainder exists in `freq`, decrement it and move to next x.
    - If not, we’ve found the smallest missing integer.
4️⃣ Return x as the answer.

🕒 Time Complexity: O(N + X), where X is the smallest missing number.
🧮 Space Complexity: O(value)
"""

class Solution:
    def findSmallestInteger(self, nums: list[int], value: int) -> int:
        freq = {}
        for i in nums:
            k = (i % value + value) % value  # handle negatives safely
            freq[k] = freq.get(k, 0) + 1

        x = 0
        while True:
            r = x % value
            if freq.get(r, 0) == 0:
                break
            freq[r] -= 1
            x += 1

        return x
