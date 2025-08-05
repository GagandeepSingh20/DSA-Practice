// 🔹 GFG Problem: Find All Triplets with Zero Sum
// 🔹 Difficulty: Medium
// 🔹 Tags: Hashing, Triplets, Arrays
"""
🧾 Problem Summary:
Given an array of integers, find all unique triplets (i, j, k) such that:
- i < j < k
- arr[i] + arr[j] + arr[k] == 0
Return all such triplets.

🔍 Example:
Input: arr = {0, -1, 2, -3, 1}
Output: {(0, 1, 4), (1, 2, 3)}
Explanation: These are the unique index triplets whose elements sum to 0.

🧠 Approach:
- Use three nested loops to check all combinations of i, j, k.
- Store values in a hashmap for constant-time lookup.
- Use a set to avoid duplicate triplets.

⏱️ Time Complexity: O(n^3)
📦 Space Complexity: O(n)
"""

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[i] = arr[i];
        }
        set<vector<int>> seen;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (auto &key : mp) {
                    int k = key.first;
                    int val = key.second;
                    if (i < j && j < k && arr[i] + arr[j] + val == 0) {
                        vector<int> temp = {i, j, k};
                        if (seen.insert(temp).second) ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};
