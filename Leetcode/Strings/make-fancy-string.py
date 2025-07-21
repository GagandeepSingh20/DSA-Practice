# Leetcode Problem: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
# Problem Number: 1957
# Problem Name: Delete Characters to Make Fancy String
# Level: Easy
# Tags: String, Greedy

"""
🧠 Problem Summary:
A "fancy" string is a string where no three consecutive characters are the same.
Given a string `s`, return the longest possible fancy string by deleting some characters.

📌 Example:
Input: s = "aaabaaaa"
Output: "aabaa"

🛠️ Approach:
- Traverse the string while keeping track of consecutive characters
- If the current character is same as previous:
  - Only allow at most 2 consecutive repetitions
- Reset the counter if a new character is encountered

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
"""

class Solution:
    def makeFancyString(self, s: str) -> str:
        cnt = 0
        ans = ""
        prev = s[0]
        
        for i in range(len(s)):
            if s[i] != prev:
                cnt = 0
                ans += s[i]
            elif cnt < 2:
                ans += s[i]
            
            prev = s[i]
            cnt += 1
        
        return ans
