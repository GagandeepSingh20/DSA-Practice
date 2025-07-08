// Leetcode Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Problem Number:121
// Problem Name: Best Time to Buy and Sell Stock
// Level: Easy
// Tags: Array, Greedy

/*
🧠 Problem Summary:
You are given an array 'prices' where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy and a different day to sell.
Return the maximum profit you can achieve from this transaction. If no profit is possible, return 0.

📌 Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price=1) and sell on day 5 (price=6), profit = 6 - 1 = 5

🛠️ Approach:
- Track the minimum price (best day to buy)
- At each step, check the potential profit and update max profit
- Time Complexity: O(n), Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int bestbuy = prices[0], maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (bestbuy > prices[i]) {
                bestbuy = prices[i];
                continue;
            }

            if (prices[i] - bestbuy > maxProfit)
                maxProfit = prices[i] - bestbuy;
        }

        return maxProfit;
    }
};

