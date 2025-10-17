"""
LeetCode 2273 — Remove Anagrams  
Difficulty: Easy  
Tags: Strings, Sorting, Two-Pointer, Vector Manipulation  

Problem Summary:
You are given a list of words.  
Repeatedly remove any word that is an **anagram** of the word immediately before it until no such pairs exist.  
Return the final list of words.

Example:
Input: words = ["abba", "baba", "bbaa", "cd", "cd"]
Output: ["abba", "cd"]

Explanation:
- "abba" and "baba" are anagrams → remove "baba"
- "abba" and "bbaa" are anagrams → remove "bbaa"
- "cd" and "cd" are anagrams → remove the second "cd"
Final list = ["abba", "cd"]

Approach:
1. Iterate through the list using index `i`.
2. Compare each word with the previous one by sorting both.
3. If they are anagrams, erase the current word.
4. Else, move to the next index.
5. Continue until all consecutive anagrams are removed.

Time Complexity: O(n * m log m)  
- n = number of words  
- m = average length of a word  
Space Complexity: O(1)
"""

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.size() == 1) return words;

        int i = 1;
        while (i < words.size()) {
            string s1 = words[i - 1], s2 = words[i];
            if (s1.length() == s2.length()) {
                sort(s1.begin(), s1.end());
                sort(s2.begin(), s2.end());
                if (s1 != s2) i++;
                else words.erase(words.begin() + i);
            } else {
                i++;
            }
        }
        return words;
    }
};
