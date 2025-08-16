// """
// Problem Link: https://leetcode.com/problems/power-of-four/
// Problem Number: 342
// Difficulty: Easy
// Tags: Math, Bit Manipulation, Recursion

// Problem Summary:
// Given an integer n, return true if it is a power of four. 
// Otherwise, return false.
// An integer n is a power of four if there exists an integer x such that n == 4^x.

// Example:
// Input: n = 16
// Output: true

// Input: n = 5
// Output: false

// Approach:
// 1. If n <= 0, return false (negative numbers and zero are invalid).
// 2. Repeatedly divide n by 4 while it's divisible by 4.
// 3. After division, if the final result is 1 → return true (it was a power of 4).
//    Else → return false.

// Time Complexity: O(log₄ n)
// Space Complexity: O(1)
// """

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        while (n % 4 == 0)
            n /= 4;
        return n == 1;
    }
};
