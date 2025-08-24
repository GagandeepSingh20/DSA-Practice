/*
LeetCode Problem: 3659. Partition Array Into K-distinct groups
Difficulty: Medium
Tags: Array, Hashing, Sorting, Greedy

Problem Summary:
You are given an integer array `nums` and an integer `k`. 
Return true if it is possible to divide `nums` into some number of subarrays such that:
- Each subarray has exactly `k` elements.
- All subarrays have the same sum.
Otherwise, return false.

Example:
Input: nums = [1,2,2,1], k = 2
Output: true
Explanation: We can divide nums into [1,2] and [2,1] with equal sum (3).

Approach:
- First check if nums.size() is divisible by k; if not, return false.
- Calculate `cnt = nums.size()/k`, the number of subarrays.
- Count the frequency of each element using a map.
- If any element occurs more than `cnt` times, return false because we cannot distribute them evenly.
- Otherwise, return true.

Time Complexity: O(n log n) [due to map]
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        int cnt = nums.size() / k;
        map<int,int> mp;
        for (auto &e : nums) {
            mp[e]++;
        }
        for (auto &it : mp) {
            if (it.second > cnt) return false;
        }
        return true;
    }
};
