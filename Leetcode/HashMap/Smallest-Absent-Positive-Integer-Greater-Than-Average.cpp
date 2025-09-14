/*
Problem: 3678. Smallest Absent Positive Integer Greater Than Average
Platform: LeetCode
Difficulty: Medium
Tags: Math, Hashing

Problem Summary:
You are given an array `nums`.  
Find the smallest positive integer that:
1. Is strictly greater than the floor of the average of nums.
2. Does not appear in nums.

Example:
Input: nums = [1,2,1,3,1]
Output: 4

Explanation:
- Average = (1+2+1+3+1)/5 = 1.6 -> floor = 1
- Smallest integer > 1 not present in nums is 4.

Approach:
1. Compute the sum of nums and build a frequency map of positive integers in nums.
2. Calculate floor(avg) = floor(sum / n).
3. Start checking from max(1, floor(avg) + 1) upwards.
4. Return the first integer not in the map.

Time Complexity: O(n + k) 
- where n = length of nums, k = difference until finding the missing integer.
Space Complexity: O(n) for the hashmap.
*/

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;

        // Build frequency map for positive integers
        for (int num : nums) {
            sum += num;
            if (num > 0) mp[num]++;
        }

        // Start from floor(avg) + 1 (but at least 1)
        double avg = (double)sum / nums.size();
        int ans = max(1, (int)floor(avg) + 1);

        // Find smallest absent positive integer
        while (true) {
            if (mp.find(ans) == mp.end()) return ans;
            ans++;
        }
        return 1; // Fallback (though loop always returns)
    }
};
