# Leetcode Problem: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
# Problem Number: 2210
# Problem Name: Count Hills and Valleys in an Array
# Level: Easy
# Tags: Array, Simulation

"""
🧠 Problem Summary:
You're given an integer array `nums`. A hill is an index i such that:
  nums[i-1] < nums[i] > nums[i+1]
A valley is an index i such that:
  nums[i-1] > nums[i] < nums[i+1]
Return the number of hills and valleys in `nums`.

📌 Example:
Input: nums = [2,4,1,1,6,5]
Output: 3
Explanation: There are 3 total: [4] is a hill, [1] is a valley, [6] is a hill.

🛠️ Approach:
- Use a loop to skip over adjacent equal values (plateaus).
- For each point, check if it is a hill or valley by comparing to previous and next distinct values.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
"""

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count = 0
        i = 1
        while i < len(nums) - 1:
            j = i + 1
            while j < len(nums) - 1 and nums[j] == nums[i]:
                j += 1
            if nums[i - 1] < nums[i] > nums[j] or nums[i - 1] > nums[i] < nums[j]:
                count += 1
            i = j
        return count
