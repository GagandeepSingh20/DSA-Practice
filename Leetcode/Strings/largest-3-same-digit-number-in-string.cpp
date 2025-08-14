"""
Problem Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/
Problem Number: 2264
Difficulty: Easy
Tags: String, Pattern Matching

Problem Summary:
Given a numeric string `num`, a good integer is defined as three identical digits in a row.
Return the largest good integer as a string. If no such integer exists, return an empty string.

Example:
Input: num = "6777133339"
Output: "777"

Approach:
1. Iterate over the string with a sliding window of size 3.
2. Check if three consecutive characters are equal.
3. Keep track of the maximum such character found.
4. Return it repeated three times if found; else return an empty string.

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution {
public:
    string largestGoodInteger(string num) {
        char curr = '\0';
        int i = 0;
        while (i < num.length() - 2) {
            if (num[i] == num[i+1] && num[i] == num[i+2] && 
                (curr == '\0' || curr < num[i])) {
                curr = num[i];
                i += 3; // skip past this sequence
            } else {
                i++;
            }
        }
        if (curr != '\0')
            return string(3, curr); // repeat char 3 times
        return "";
    }
};
