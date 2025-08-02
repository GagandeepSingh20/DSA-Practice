// LeetCode Problem: https://leetcode.com/problems/rearranging-fruits/
// Problem Number: 2561
// Problem Name: Rearranging Fruits
// Difficulty: Hard
// Tags: Greedy, Array, HashMap, Sorting

/*
🧠 Problem Summary:
You are given two integer arrays `basket1` and `basket2` representing fruits in two baskets.
You can swap any two fruits, one from each basket. The goal is to make both baskets identical
(minimum swaps). Each swap has a cost: minimum of the two swapped fruit values or 
twice the minimum fruit value present in any basket.

Return the minimum total cost to make the baskets equal or -1 if it's not possible.

📌 Example:
Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1

🛠️ Approach:
1. Count the frequency difference of each fruit between the two baskets.
2. If any difference is odd, return -1 (impossible to balance).
3. From the surplus in both baskets, form swap candidates.
4. Sort b1 ascending and b2 descending for optimal swap.
5. Cost is the minimum of direct swap or double the smallest element across both baskets.

🧮 Time Complexity: O(n log n) for sorting swap candidates.
🧮 Space Complexity: O(n) for frequency map and swap arrays.
*/

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        if(basket1.size() == 1) {
            if (basket1[0] == basket2[0]) return 0;
            return -1;
        }

        int n = basket1.size();
        map<int, int> mp;
        int minElement = INT_MAX;

        // Step 1: Count frequency differences
        for (int i = 0; i < n; i++) {
            mp[basket1[i]] += 1;
            mp[basket2[i]] -= 1;
            minElement = min({minElement, basket1[i], basket2[i]});
        }

        vector<int> b1, b2;
        for (auto [key, value] : mp) {
            if (value % 2 != 0) return -1;
            int freq = abs(value) / 2;

            if (value < 0) {
                for (int k = 0; k < freq; k++) b1.push_back(key);
            } else if (value > 0) {
                for (int k = 0; k < freq; k++) b2.push_back(key);
            }
        }

        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end(), greater<int>());

        long long cost = 0;
        for (int i = 0; i < b1.size(); i++) {
            cost += min(1LL * min(b1[i], b2[i]), 2LL * minElement);
        }

        return cost;
    }
};
