"""
Problem: Print Anagrams Together
Platform: GeeksforGeeks
Difficulty: Medium
Tags: Hashing, Sorting, Strings

Problem Summary:
Given an array of strings, the task is to group all anagrams together.
An anagram is a word formed by rearranging the letters of another word.
The output should be a list of lists, where each list contains strings that are anagrams of each other.

Example:
Input:
N = 5
words[] = {act, god, cat, dog, tac}
Output:
god dog
act cat tac

Approach:
1. Create an unordered_map<string, vector<string>> where:
   - Key = sorted version of the string
   - Value = list of strings that are anagrams of this key
2. Traverse all words, sort each word, and add it to the corresponding key in the map.
3. Extract all groups from the map and return as the result.

Time Complexity: O(N * K log K)  (N = number of strings, K = length of each string for sorting)
Space Complexity: O(N * K)       (for storing the groups)
"""

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        
        // Hash map to store sorted string as key and list of anagrams as value
        unordered_map<string, vector<string>> mp;
        
        for (int i = 0; i < arr.size(); i++) {
            string key = arr[i];
            sort(key.begin(), key.end());  // Sort to generate a common key for anagrams
            mp[key].push_back(arr[i]);
        }
        
        // Collect all anagram groups
        for (auto &it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

