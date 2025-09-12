"""
Problem: Vowels Game in a String
LeetCode Link: https://leetcode.com/problems/vowels-game-in-a-string/
Problem Number: 3227
Difficulty: Easy
Tags: String, Game Theory

Summary:
Alice and Bob are playing a game with a string `s`:
- Alice starts first.
- A player can remove any vowel ('a','e','i','o','u') from the string during their turn.
- The game continues until there are no vowels left.
- The player unable to make a move loses.

Return True if Alice wins, otherwise False.

Example:
Input: s = "abc"
Output: True
Explanation:
- Alice removes 'a' → "bc".
- Bob has no valid moves → Alice wins.

Approach:
- The game boils down to checking if there is at least one vowel in the string.
- If there is at least one vowel → Alice can always remove it on her first turn → Alice wins.
- If there are no vowels → Alice cannot make a move → Alice loses.

Time Complexity: O(n), where n = length of the string.
Space Complexity: O(1).
"""

class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        for ch in s:
            if ch in vowels:
                return True
        return False
