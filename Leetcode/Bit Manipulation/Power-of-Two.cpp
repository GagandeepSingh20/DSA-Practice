// Leetcode Problem: https://leetcode.com/problems/power-of-two/
// Problem Number: 231
// Problem Name: Power of Two
// Level: Easy
// Tags: Math, Bit Manipulation, Recursion

"""
🧠 Problem Summary:
Given an integer `n`, return `true` if it is a power of two, otherwise return `false`.

📌 Example:
Input: n = 1  
Output: true  
Explanation: 2^0 = 1

Input: n = 16  
Output: true  
Explanation: 2^4 = 16

Input: n = 3  
Output: false

🛠️ Approach:
- A power of two is of the form 2^k for k >= 0.
- Base case: If `n == 1`, return true (2^0 = 1).
- If `n` is zero, return false.
- Recursively check if `n` is divisible by 2 and call the function on `n / 2`.

🧮 Time Complexity: O(log n) — Each recursive step divides n by 2.
🧮 Space Complexity: O(log n) — Due to recursion stack.
"""

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n == 0) return false;
        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};
