// """
// LeetCode Problem 128: Longest Consecutive Sequence
// Difficulty: Medium
// Tags: Array, Hash Table, Union Find

// Problem Summary:
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Example:
// Input: nums = [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive sequence is [1, 2, 3, 4].

// Approach:
// 1. Insert all elements into a map to avoid duplicates and keep order.
// 2. Traverse the map and count consecutive sequences.
// 3. Track the maximum length encountered.

// Time Complexity: O(n log n)   (because of std::map)
// Space Complexity: O(n)
// """

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if (arr.size() == 0) return 0;
        if (arr.size() == 1) return 1;
        
        map<int,int> mp;
        for (auto &e : arr) {
            mp[e] += 1;  // store occurrences
        }
        
        auto it = mp.begin();
        int prev = it->first, cnt = 1, temp = 1;
        it++;
        
        for (; it != mp.end(); it++) {
            if (prev + 1 != it->first) {
                cnt = max(cnt, temp);
                prev = it->first;
                temp = 1;
            } else {
                prev = it->first;
                temp++;
            }
        }
        
        cnt = max(cnt, temp);
        return cnt;
    }
};
