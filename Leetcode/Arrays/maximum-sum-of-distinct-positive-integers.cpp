// Leetcode Problem: https://leetcode.com/problems/maximum-sum-of-distinct-positive-integers/
// Problem Number: 3487
// Problem Name: Maximum Sum of Distinct Positive Integers
// Level: Easy
// Tags: Hash Map, Array, Greedy

/*
🧠 Problem Summary:
You're given an array `nums`. Your task is to return the **sum of distinct positive integers**.
If there are no positive integers, return the **maximum negative number**.

📌 Example:
Input: nums = [1, -2, 3, 3, -4, 5]
Output: 9  // (1 + 3 + 5)

🛠️ Approach:
- Use an unordered map to track if a number has been added already.
- Add only the **positive numbers** once.
- If all elements are non-positive, return the **maximum among them**.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
*/

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int minNegative = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] == 1) continue;

            if (nums[i] > 0) {
                sum += nums[i];
                mp[nums[i]] = 1;
            } else if (nums[i] <= 0 && minNegative < nums[i]) {
                minNegative = nums[i];
            }
        }

        return sum > 0 ? sum : minNegative;
    }
};
