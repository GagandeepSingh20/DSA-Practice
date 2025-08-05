# Leetcode Problem: https://leetcode.com/problems/fruits-into-baskets-ii/
# Problem Number: 3477
# Problem Name: Fruits Into Baskets II
# Level: Medium
# Tags: Greedy, Array, Hash Map

"""
🧠 Problem Summary:
You are given two integer arrays:
- `fruits[i]`: number of fruits at position `i`
- `baskets[i]`: capacity of the basket at position `i`

Rules:
- Each fruit group at `fruits[i]` needs to be placed in one basket.
- You may place a group in any basket that has capacity ≥ group size.
- Each basket can be used only once.

Return the **number of fruit groups** that cannot be placed into any basket.

📌 Example:
Input: fruits = [1,3,2], baskets = [2,2,2]  
Output: 1  
Explanation: We can place fruits[0]=1 in any 2-capacity basket, fruits[1]=3 cannot be placed anywhere, fruits[2]=2 goes in remaining basket.

🛠️ Approach:
- Store all basket capacities using a map (index → capacity).
- For each fruit group, try placing it into the first available basket that can hold it.
- Remove that basket once used.
- Count how many baskets remain unused, which gives the number of unplaced fruits.

🧮 Time Complexity: O(n²) in worst case (if baskets must be scanned for each fruit)
🧮 Space Complexity: O(n) for storing the map
"""

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[i] = baskets[i];
        }

        for (int i = 0; i < n; i++) {
            for (auto& key : mp) {
                if (key.second >= fruits[i]) {
                    mp.erase(key.first);
                    break;
                }
            }
        }

        return mp.size();
    }
};
