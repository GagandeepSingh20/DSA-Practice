/*
GFG Problem: Count Subarrays with Sum K
Problem Link: https://www.geeksforgeeks.org/problems/count-subarrays-with-given-sum/1

Difficulty: Medium
Tags: Hashing, Prefix Sum, Subarray, Unordered Map

Problem Summary:
Given an array of integers and an integer k, count the total number of subarrays whose sum equals k.

Example:
Input:
arr = [10, 2, -2, -20, 10], k = -10
Output:
3
Explanation:
Subarrays with sum -10 are:
[10, 2, -2, -20], [2, -2, -20, 10], [-20, 10]

Approach:
- Use prefix sum and hashing to keep track of how many times a prefix_sum - k has appeared.
- Initialize mp[0] = 1 to handle the case where prefix_sum itself equals k.
- Iterate through the array, maintain prefix_sum, and update count when (prefix_sum - k) exists in map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int cnt = 0, prefix_sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;  // To handle subarray starting from index 0
        
        for (int num : arr) {
            prefix_sum += num;
            
            if (mp.find(prefix_sum - k) != mp.end()) {
                cnt += mp[prefix_sum - k];
            }
            mp[prefix_sum]++;
        }
        return cnt;
    }
};
