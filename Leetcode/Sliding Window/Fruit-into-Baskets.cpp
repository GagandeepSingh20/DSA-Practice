
// Leetcode Problem Link: https://leetcode.com/problems/fruit-into-baskets/
// Problem Number: 904. Fruit Into Baskets
// Difficulty: Medium
// Tags: Sliding Window, Hash Map
"""

Problem Summary:
You are given an array fruits where fruits[i] is the type of fruit. 
You are allowed to pick at most two different types of fruits, and you must pick them in a continuous subarray. 
Return the maximum number of fruits you can pick.

Example:
Input: fruits = [1,2,1]
Output: 3

Approach:
- Use a sliding window to keep track of a window containing at most two fruit types.
- Use an unordered_map to store the count of each fruit type in the current window.
- Move the right pointer to expand the window.
- If the number of unique fruit types exceeds 2, move the left pointer to shrink the window.
- Keep track of the maximum window size.

Time Complexity: O(n)
Space Complexity: O(1) — since the number of fruit types is bounded (map size ≤ 2)

"""
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;

        int left = 0, maxFruits = 0;
        for(int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};
