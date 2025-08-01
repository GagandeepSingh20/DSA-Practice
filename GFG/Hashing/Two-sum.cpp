// GFG Problem: https://www.geeksforgeeks.org/problems/two-sum/1
// Problem Name: Two Sum
// Difficulty: Easy
// Tags: Hashing, Arrays

/*
🧠 Problem Summary:
Given an array of integers and a target value, determine whether there are two distinct indices i and j
such that arr[i] + arr[j] == target.

📌 Example:
Input: arr = {2, 6, 5, 8, 11}, target = 14
Output: true
Explanation: 6 + 8 = 14

🛠️ Approach:
- Use a hash map to store array elements with their indices.
- For each element, check if (target - arr[i]) exists in the map and is not the same index.
- Return true if such a pair is found.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
*/

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]] = i;
        }
        for(int i=0; i<arr.size(); i++) {
            if(mp.find(target - arr[i]) != mp.end() && i != mp[target - arr[i]])
                return true;
        }
        return false;
    }
};
