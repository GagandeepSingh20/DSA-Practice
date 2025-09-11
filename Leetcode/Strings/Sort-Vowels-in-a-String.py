"""
Problem: Sort Vowels in a String
LeetCode Link: https://leetcode.com/problems/sort-vowels-in-a-string/
Problem Number: 2785
Difficulty: Medium
Tags: String, Sorting

Summary:
You are given a string s.  
Rearrange the vowels of s in non-decreasing order while keeping the consonants in their original positions.  
Return the resulting string.

Example:
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation:
- Extract vowels: [E, e, O, e]
- Sort them: [E, O, e, e]
- Place them back: "lEOtcede"

Approach:
1. Extract all vowels from the string and store them in a list.
2. Sort the list of vowels.
3. Traverse the string again:
   - If the character is a vowel, replace it with the next sorted vowel.
   - Otherwise, keep the original character.
4. Return the new string.

Time Complexity: O(n log n) due to sorting vowels.
Space Complexity: O(n) for storing vowels and result string.
"""

class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        vlist = [ch for ch in s if ch in vowels]
        vlist.sort()

        j = 0
        result = []
        for ch in s:
            if ch in vowels:
                result.append(vlist[j])
                j += 1
            else:
                result.append(ch)
        
        return "".join(result)
