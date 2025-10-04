"""
🧠 Problem Link: https://leetcode.com/problems/container-with-most-water/
📌 Problem Number: 11
📚 Name: Container With Most Water
🟢 Difficulty: Medium
🏷️ Tags: Array, Two Pointers, Greedy

📝 Problem Summary:
You are given an integer array `height` of length `n`. 
There are `n` vertical lines drawn such that the two endpoints of the i-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

⚠️ Note: You may not slant the container.

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The max area is formed between heights 8 and 7 (indices 1 and 8).

✅ Approach (Two Pointers):
1. Use two pointers `i` (start) and `j` (end).
2. At each step, calculate the area formed by the two lines.
3. Move the pointer pointing to the shorter line inward (since moving the longer one won't increase area).
4. Continue until `i` and `j` meet.

⏱️ Time Complexity: O(n) – each element is checked at most once.
📦 Space Complexity: O(1) – no extra space used.
"""

from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j = 0, len(height) - 1
        area = 0
        
        while i < j:
            # Calculate current area
            h = min(height[i], height[j])
            w = j - i
            area = max(area, h * w)

            # Move pointer at the shorter line
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        
        return area
