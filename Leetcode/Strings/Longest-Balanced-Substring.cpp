/*
🔗 Problem Link: https://leetcode.com/problems/longest-balanced-substring/
🏷️ Problem No: 3713
📚 Problem Name: Longest Balanced Substring
🧩 Difficulty: Medium
🧠 Tags: String, Hash Map, Sliding Window, Brute Force

📝 Problem Summary:
Given a string `s`, find the length of the longest substring where all characters
appear the same number of times. 

A substring is considered balanced if the frequency of every distinct character 
in that substring is equal.

📘 Example:
Input: s = "aabbcc"
Output: 6
Explanation: The entire string is balanced because all characters appear twice.

Input: s = "aabbb"
Output: 3
Explanation: The substring "bbb" is balanced.

💡 Approach:
1️⃣ Iterate over all possible starting indices `i`.
2️⃣ For each start `i`, expand the substring till `j` and maintain a frequency map.
3️⃣ After every addition, check if all frequencies are equal:
   - Store first frequency as reference.
   - If all characters match it, update `len` to max length.
4️⃣ Return the maximum balanced substring length found.

🕒 Time Complexity: O(N² * M) 
(where N = length of string, M = number of distinct characters in substring)
🧮 Space Complexity: O(M)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                int prev = -1;
                bool flag = true;

                for (auto &it : mp) {
                    if (prev == -1) prev = it.second;
                    else if (it.second != prev) {
                        flag = false;
                        break;
                    }
                }

                if (flag) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};
