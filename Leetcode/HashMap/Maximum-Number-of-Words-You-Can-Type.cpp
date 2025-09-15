// File: 1935-Maximum-Number-of-Words-You-Can-Type.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
 * Problem Number: 1935
 * Problem Name: Maximum Number of Words You Can Type
 * Difficulty: Easy
 * Tags: String, Hash Set
 *
 * Problem Summary:
 * You are given a string `text` consisting of words separated by spaces, and 
 * a string `brokenLetters` representing the letters of a broken keyboard. 
 * A word cannot be typed if it contains any of the broken letters. 
 * Return the number of words in `text` that can be fully typed using this keyboard.
 *
 * Example:
 * Input: text = "hello world", brokenLetters = "ad"
 * Output: 1
 * Explanation: Only "world" can be typed.
 *
 * Input: text = "leet code", brokenLetters = "lt"
 * Output: 1
 * Explanation: Only "code" can be typed.
 *
 * Approach:
 *  - Store broken letters in an unordered_set for O(1) lookup.
 *  - Traverse the string `text` character by character.
 *  - Use a flag to track whether the current word can be typed.
 *  - If any broken letter appears in the current word, mark flag = false.
 *  - When reaching a space or end of text, count the word if flag == true.
 *
 * Time Complexity: O(N), where N = length of text
 * Space Complexity: O(B), where B = number of broken letters
 */

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int cnt = 0, i = 0;
        bool flag = true;

        while (i < text.length()) {
            if (broken.count(text[i])) 
                flag = false;
            i++;

            if (i == text.length() || text[i] == ' ') {
                if (flag) cnt++;
                flag = true; // reset for next word
            }
        }
        return cnt;
    }
};
