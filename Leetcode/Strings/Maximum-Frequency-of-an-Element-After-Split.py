"""
Problem: 3541. Maximum Frequency of an Element After Split
Platform: LeetCode
Difficulty: Medium
Tags: Hash Map, String, Frequency Counting

Problem Summary:
Given a string s, you can split it into vowels and consonants. 
Return the sum of:
- The maximum frequency among consonants.
- The maximum frequency among vowels.

Example:
Input: s = "abcdeeeiou"
Output: 6
Explanation:
- Most frequent consonant: 'b' or 'c' (freq = 1).
- Most frequent vowel: 'e' (freq = 3).
Answer = 1 + 3 = 4.

Approach:
- Maintain two hash maps: one for vowels, one for consonants.
- Count occurrences of each character.
- Take max frequency from each group if non-empty.
- Return their sum.

Time Complexity: O(n), where n = len(s)
Space Complexity: O(26) ≈ O(1) (constant extra space)
"""

class Solution:
    def maxFreqSum(self, s: str) -> int:
        c = {}  # consonant frequency map
        v = {}  # vowel frequency map
        vowels = ['a', 'e', 'i', 'o', 'u']

        for i in s:
            if i in vowels:
                v[i] = v.get(i, 0) + 1
            else:
                c[i] = c.get(i, 0) + 1

        ans = 0
        if c: ans += max(c.values())
        if v: ans += max(v.values())
        return ans
