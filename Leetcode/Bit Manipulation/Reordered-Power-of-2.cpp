 // Leetcode Problem: https://leetcode.com/problems/reordered-power-of-2/
 // Problem Number: 869
 // Problem Name: Reordered Power of 2
 // Level: Medium
 // Tags: Math, Backtracking, Bit Manipulation, Permutations

"""
🧠 Problem Summary:
Given an integer `n`, return true if and only if we can reorder the digits of `n` in any order so that the new number is a power of two.

📌 Example:
Input: n = 1  
Output: true  
Explanation: 1 is 2^0.

Input: n = 10  
Output: false  
Explanation: No rearrangement forms a power of two.

🛠️ Approach:
- Extract the digits of `n`.
- Sort digits to handle duplicates efficiently.
- Use backtracking to generate all permutations.
- Skip permutations with leading zeros.
- Check if the formed number is a power of two using bit manipulation.

🧮 Time Complexity: O(k! * k) — k = number of digits in `n`.
🧮 Space Complexity: O(k) — recursion stack.
"""

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end()); // handle duplicates efficiently
        return permuteAndCheck(digits, 0);
    }

private:
    bool permuteAndCheck(vector<int> &digits, int i) {
        if (i == digits.size()) {
            if (digits[0] == 0) return false; // leading zero not allowed
            long long num = 0;
            for (int d : digits) num = num * 10 + d;
            return Power_of_Two(num);
        }
        for (int j = i; j < digits.size(); j++) {
            if (j != i && digits[j] == digits[i]) continue; // skip duplicates
            swap(digits[i], digits[j]);
            if (permuteAndCheck(digits, i + 1)) return true;
            swap(digits[i], digits[j]);
        }
        return false;
    }

    bool Power_of_Two(long long num) {
        return num > 0 && (num & (num - 1)) == 0;
    }
};
