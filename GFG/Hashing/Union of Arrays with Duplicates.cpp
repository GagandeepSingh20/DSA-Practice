// """
// GFG Problem: Union of Arrays with Duplicates
// Difficulty: Easy
// Tags: Hashing, Arrays, Union

// Problem Summary:
// Given two arrays 'a' and 'b', we need to find their union (all unique elements
// present in either array). Duplicates should not appear in the result.

// Example:
// Input:
// a = [1, 2, 3, 4]
// b = [3, 4, 5, 6]
// Output: [1, 2, 3, 4, 5, 6]

// Approach:
// - Use an unordered_map (or unordered_set) to keep track of all unique elements.
// - Insert all elements from both arrays into the map.
// - Collect the keys of the map into the result vector.

// Time Complexity: O(n + m), where n = size of a, m = size of b
// Space Complexity: O(n + m) for the hash map
// """

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        // Insert elements of first array
        for (int i = 0; i < a.size(); i++) {
            mp[a[i]] += 1;
        }
        
        // Insert elements of second array
        for (int j = 0; j < b.size(); j++) {
            mp[b[j]] += 1;
        }
        
        // Collect unique keys into result
        for (auto &pair : mp) {
            ans.push_back(pair.first);
        }
        
        return ans;
    }
};
