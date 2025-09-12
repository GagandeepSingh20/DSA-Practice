/*
Problem: Count Subarrays with given XOR
Platform: GeeksforGeeks (GFG)
Problem Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
Difficulty: Medium
Tags: Arrays, Hashing, Prefix-XOR

Summary:
Given an array arr[] and an integer K, count the number of subarrays such that 
the XOR of elements in those subarrays is equal to K.

Example:
Input:
N = 4, K = 6
arr[] = [4, 2, 2, 6]

Output:
4

Explanation:
The subarrays with XOR = 6 are:
[4, 2], [2, 2, 6], [6], [4, 2, 2]

Approach:
- Use prefix XOR and hashing:
  - Maintain the current prefix XOR while traversing.
  - For each element, compute x = prefixXor ^ K.
  - The number of times 'x' has appeared in the map indicates the number of subarrays ending at the current index with XOR = K.
- Increment count accordingly and update the map.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long cnt = 0;
        int xr = 0;
        unordered_map<int, int> mp;
        mp[xr] = 1; // base case: XOR = 0 before starting
        
        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i]; // update prefix xor
            int x = xr ^ k; 
            
            // if prefix xor up to some j gives x, then subarray (j+1..i) has xor = k
            if (mp.find(x) != mp.end()) {
                cnt += mp[x];
            }
            
            mp[xr]++;
        }
        return cnt;
    }
};
