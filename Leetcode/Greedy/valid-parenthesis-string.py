# Leetcode Problem: https://leetcode.com/problems/valid-parenthesis-string/
# Problem Number: 678
# Problem Name: Valid Parenthesis String
# Level: Medium
# Tags: Stack, String, Greedy

"""
🧠 Problem Summary:
Given a string `s` containing only '(', ')' and '*', check whether it is a valid parenthesis string.

Rules:
- '(' must be closed by ')'
- '*' can be treated as '(', ')' or empty
- An empty string is also valid

📌 Example:
Input: s = "(*))"
Output: True

🛠️ Approach:
- Use two stacks:
  1. `s1` to store indices of '('
  2. `s2` to store indices of '*'
- On encountering ')':
  - Try to match with last '(' (from `s1`), else match with '*' (from `s2`)
  - If neither exists → invalid
- After processing:
  - Check if remaining '(' can be matched by '*' coming **after** them
  - If not, return False

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
"""

class Solution:
    def checkValidString(self, s: str) -> bool:
        s1 = []  # stack for '(' positions
        s2 = []  # stack for '*' positions

        for i, ch in enumerate(s):
            if ch == '(':
                s1.append(i)
            elif ch == '*':
                s2.append(i)
            else:  # ch == ')'
                if s1:
                    s1.pop()
                elif s2:
                    s2.pop()
                else:
                    return False

        # Try to match remaining '(' with '*' (only if * comes after '(')
        while s1 and s2:
            if s1[-1] < s2[-1]:
                s1.pop()
                s2.pop()
            else:
                break

        return not s1
