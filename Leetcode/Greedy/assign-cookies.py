# Leetcode Problem: https://leetcode.com/problems/assign-cookies/
# Problem Number: 455
# Problem Name: Assign Cookies
# Level: Easy
# Tags: Greedy, Sorting

"""
🧠 Problem Summary:
You are given two integer arrays:
- g[i]: greed factor of the i-th child
- s[j]: size of the j-th cookie

Each child i can be content if there's a cookie j such that s[j] >= g[i],
and each cookie can be assigned to at most one child.

Return the maximum number of content children.

📌 Example:
Input: g = [1,2,3], s = [1,1]
Output: 1

🛠️ Approach:
- Sort both `g` and `s` arrays
- Use two pointers starting from the end
- Try to satisfy the greediest child with the biggest available cookie
- If successful, move both pointers
- Else, move only the child pointer

🧮 Time Complexity: O(n log n + m log m)
🧮 Space Complexity: O(1)
"""

from typing import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        if len(s) == 0:
            return 0

        s.sort()
        g.sort()
        i = len(g) - 1
        j = len(s) - 1
        cnt = 0

        while i >= 0 and j >= 0:
            if s[j] >= g[i]:
                cnt += 1
                j -= 1
                i -= 1
            else:
                i -= 1

        return cnt
