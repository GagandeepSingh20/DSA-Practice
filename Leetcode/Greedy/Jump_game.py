# Leetcode Problem: https://leetcode.com/problems/jump-game/
# Problem Number: 55
# Problem Name: Jump Game
# Level: Medium
# Tags: Greedy, Array, Dynamic Programming

"""
🧠 Problem Summary:
Given an array `nums` where each element represents your maximum jump length at that position,
determine if you can reach the last index starting from index 0.

📌 Example:
Input: nums = [2,3,1,1,4]
Output: True

🛠️ Approach:
- Use a greedy strategy from the end of the array
- Initialize `target` as the last index
- Traverse backwards:
  - If the current index can reach the `target`, update the `target` to this index
- Finally, if you can reach index 0, return True

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
"""

from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] + i >= target:
                target = i
        return target == 0
