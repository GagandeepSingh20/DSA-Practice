# Leetcode Problem: https://leetcode.com/problems/maximum-score-from-removing-substrings/
# Problem Number: 1717
# Problem Name: Maximum Score From Removing Substrings
# Level: Medium
# Tags: Stack, Greedy, String

"""
🧠 Problem Summary:
You are given a string `s` and two integers `x` and `y`.
You can remove "ab" and gain `x` points or remove "ba" and gain `y` points.
You can perform these operations any number of times and in any order.
Return the maximum score you can get.

📌 Example:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19

🛠️ Approach:
- To maximize score, always remove the higher scoring pair first (either "ab" or "ba").
- Use a stack to simulate the removals greedily.
- First pass removes the higher-scoring substring.
- Second pass on the remaining characters removes the other substring.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
"""

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        stack = []
        score = 0

        if x > y:
            # Prioritize removing "ab"
            for ch in s:
                if stack and stack[-1] == 'a' and ch == 'b':
                    stack.pop()
                    score += x
                else:
                    stack.append(ch)

            # Remove "ba" from remaining stack
            temp = []
            while stack:
                ch = stack.pop()
                if temp and temp[-1] == 'a' and ch == 'b':
                    temp.pop()
                    score += y
                else:
                    temp.append(ch)
        else:
            # Prioritize removing "ba"
            for ch in s:
                if stack and stack[-1] == 'b' and ch == 'a':
                    stack.pop()
                    score += y
                else:
                    stack.append(ch)

            # Remove "ab" from remaining stack
            temp = []
            while stack:
                ch = stack.pop()
                if temp and temp[-1] == 'b' and ch == 'a':
                    temp.pop()
                    score += x
                else:
                    temp.append(ch)

        return score
