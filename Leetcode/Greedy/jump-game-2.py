# Leetcode Problem: https://leetcode.com/problems/jump-game-ii/
# Problem Number: 45
# Problem Name: Jump Game II
# Level: Medium
# Tags: Greedy, Array, BFS-like

"""
🧠 Problem Summary:
Given an array `nums`, where each element represents your max jump length at that index,
return the minimum number of jumps to reach the last index.

You can assume that you can always reach the end.

📌 Example:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

🛠️ Approach:
- Use a BFS-style greedy strategy:
  - Track the current range (`l` to `r`) where you can jump from
  - In each iteration, calculate the farthest index you can reach from the current range
  - Increase the jump count `res` each time you move to a new range

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
"""

from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        l = r = 0

        while r < len(nums) - 1:
            farthest = 0
            for i in range(l, r + 1):
                farthest = max(farthest, nums[i] + i)
            l = r + 1
            r = farthest
            res += 1

        return res
