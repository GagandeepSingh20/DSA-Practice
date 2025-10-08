/*
🔗 Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
📌 Problem Number: 2300
📚 Name: Successful Pairs of Spells and Potions
🟠 Difficulty: Medium
🏷️ Tags: Array, Binary Search, Sorting, Two Pointers

📝 Problem Summary:
You are given two integer arrays `spells` and `potions` and an integer `success`.
A pair (spells[i], potions[j]) is considered successful if:
    spells[i] * potions[j] >= success

For each spell, return the number of potions that form a successful pair with it.

Example:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- For spell 5: pairs with potions [2,3,4,5] → 4
- For spell 1: none → 0
- For spell 3: pairs with potions [3,4,5] → 3

✅ Approach:
- Sort `potions` for binary search.
- For each spell:
  - Use binary search to find the first potion index where `spell * potion >= success`.
  - All potions to the right of that index form successful pairs.
- Result = total potions - found index.

⏱️ Time Complexity: O(n log m), where n = spells.size(), m = potions.size()
📦 Space Complexity: O(1) extra (ignoring output vector)
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());

        for (int spell : spells) {
            int s = 0, e = potions.size() - 1, point = potions.size();

            // Binary search for first valid potion
            while (s <= e) {
                int mid = s + (e - s) / 2;
                long long product = 1LL * spell * potions[mid];

                if (product >= success) {
                    point = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            pairs.push_back(potions.size() - point);
        }

        return pairs;
    }
};
