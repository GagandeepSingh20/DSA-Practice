/*
🔗 Problem Link: https://leetcode.com/problems/sum-of-values-divisible-by-k/
🏷️ Problem No: 3712
📚 Problem Name: Sum of Values Divisible by K
🧩 Difficulty: Easy
🧠 Tags: Hash Map, Array, Counting

📝 Problem Summary:
You are given an integer array `nums` and an integer `k`.  
Find the sum of all elements `x` in `nums` such that the **frequency** of `x` in the array is divisible by `k`.  

Formally, for every distinct element `x`:
- Let `freq[x]` = number of times `x` appears in `nums`
- If `freq[x] % k == 0`, then add `(x * freq[x])` to the total sum.

Return the total sum.

📘 Example:
Input: nums = [2, 3, 2, 3, 3], k = 2  
Output: 4  
Explanation:  
- freq[2] = 2 → divisible by 2 → contributes 2 * 2 = 4  
- freq[3] = 3 → not divisible by 2  
Total = 4

💡 Approach:
1️⃣ Use an unordered_map to count the frequency of each element.  
2️⃣ Iterate through the map:
   - If frequency is divisible by k, add `element * frequency` to sum.  
3️⃣ Return the final sum.

🕒 Time Complexity: O(N)
🧮 Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;

        for (auto &e : nums) {
            mp[e]++;
        }

        for (auto &it : mp) {
            if (it.second % k == 0) {
                sum += it.first * it.second;
            }
        }

        return sum;
    }
};
