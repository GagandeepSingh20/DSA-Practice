/*
🔗 Problem Link: https://leetcode.com/problems/maximum-total-damage-with-spell-power/
🏷️ Problem No: 3186
📚 Problem Name: Maximum Total Damage With Spell Power
🧩 Difficulty: Medium
🧠 Tags: Dynamic Programming, Binary Search, Hash Map

📝 Problem Summary:
You are given an integer array `power`, where each value represents the power level of a spell.  
When you use a spell of power `x`, all spells with powers `x - 2`, `x - 1`, `x`, `x + 1`, and `x + 2` become unusable.  

Your goal is to select a subset of spells to **maximize the total damage**,  
where the total damage is defined as the sum of `(power[i] * frequency of power[i])`  
for each selected spell type.

Return the maximum total damage you can achieve.

📘 Example:
Input: power = [1, 1, 3, 4]
Output: 6  
Explanation:
- You can choose power 1 (damage = 2) and power 4 (damage = 4)
- Total = 6

💡 Approach:
1️⃣ Count frequency of each unique power using a hash map.  
2️⃣ Sort all unique powers into a list.  
3️⃣ Use **Dynamic Programming + Binary Search**:
    - For each index `i`, you can either:
      - Skip `i` → take result from `i + 1`
      - Take `i` → gain `nums[i] * freq[nums[i]]` + result from the next non-conflicting spell (found by binary search for `nums[i] + 3`)
4️⃣ Recurrence:  
   `dp[i] = max(dp[i+1], nums[i]*freq[nums[i]] + dp[next_index])`

🕒 Time Complexity: O(N log N)
🧮 Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> t;

    long long solve(vector<long long> &nums, int i, unordered_map<long long, long long> &mp) {
        if (i >= nums.size()) return 0;
        if (t[i] != -1) return t[i];

        long long skip = solve(nums, i + 1, mp);

        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        long long take = nums[i] * mp[nums[i]] + solve(nums, j, mp);

        return t[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> mp;

        for (int i = 0; i < power.size(); i++) {
            mp[power[i]]++;
        }

        vector<long long> temp;
        for (auto &it : mp) {
            temp.push_back(it.first);
        }
        sort(temp.begin(), temp.end());

        t.assign(temp.size() + 1, -1);
        return solve(temp, 0, mp);
    }
};
