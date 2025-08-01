// Leetcode Problem: https://leetcode.com/problems/pascals-triangle/
// Problem Number: 118
// Problem Name: Pascal's Triangle
// Level: Easy
// Tags: Array, Dynamic Programming

/*
🧠 Problem Summary:
Given an integer numRows, return the first numRows of Pascal's triangle.
Each number is the sum of the two numbers directly above it.

📌 Example:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

🛠️ Approach:
- Start with the first row [1].
- For each subsequent row, use the values from the previous row to compute current values.
- Each element (except first and last) is the sum of two elements directly above it.

🧮 Time Complexity: O(numRows^2)
🧮 Space Complexity: O(numRows^2) for storing the triangle
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        int i = 0;
        while (i < numRows - 1) {
            int j = 0;
            vector<int> temp;
            while (j < res[i].size()) {
                if (j == 0) temp.push_back(1);
                else temp.push_back(res[i][j] + res[i][j - 1]);
                j++;
            }
            temp.push_back(1);
            res.push_back(temp);
            i++;
        }
        return res;
    }
};
