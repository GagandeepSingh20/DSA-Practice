// Leetcode Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Problem No: 1752
// Problem Name: Check if Array Is Sorted and Rotated
// Level: Easy
// Tags: Array, Greedy

/*
🧠 Problem Summary:
Given an array of n integers, check if it could become non-decreasing by rotating it some number of times (including zero).

📌 Example:
Input: nums = [3, 4, 5, 1, 2]
Output: true

Input: nums = [2, 1, 3, 4]
Output: false

🛠️ Approach:
- Count how many times nums[i] > nums[i+1]
- If the count is more than 1 → not sortable by rotation
- Handle circular comparison between last and first element

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {//this condition will only work for one time i.e. when largest element compared with smallest element
                count++;
            }
        }
        if ( count <= 1)return true;
        return false;
    }
};class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};
