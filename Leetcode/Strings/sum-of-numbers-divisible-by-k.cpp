"""
LeetCode 3712 — Sum of Numbers Divisible by K  
Difficulty: Easy  
Tags: Hash Map, Frequency Counting  

Problem Summary:
Given an array `nums` and an integer `k`, find the sum of all elements `x` such that the frequency 
of `x` in the array is divisible by `k`.  

Example:
Input: nums = [2, 3, 3, 2, 2, 4], k = 2  
Output: 10  
Explanation:
Frequencies: 2 → 3, 3 → 2, 4 → 1  
Only number 3 has frequency divisible by 2 → 3 * 2 = 6  
But if any other number also satisfies (like 2 appearing 4 times, etc.), we include its total.  

Approach:
1. Use an unordered_map to count the frequency of each element.  
2. Traverse the map and check if the frequency is divisible by `k`.  
3. If yes, add `(element * frequency)` to the result.  
4. Return the total sum.

Time Complexity: O(n)  
Space Complexity: O(n)
"""

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;

        // Count frequency of each element
        for (auto &e : nums) {
            mp[e]++;
        }

        // Check for elements whose frequency is divisible by k
        for (auto &it : mp) {
            if (it.second % k == 0) {
                sum += it.first * it.second;
            }
        }

        return sum;
    }
};
