/**
 * LeetCode Problem: https://leetcode.com/problems/sort-matrix-by-diagonals/
 * Problem Number: 3446
 * Problem Name: Sort Matrix by Diagonals
 * Difficulty: Medium
 * Tags: Matrix, Sorting, Diagonal Traversal
 *
 * Problem Summary:
 * You are given an n x n integer matrix `grid`. You need to sort:
 * - The elements of each diagonal starting from the top row (except first element) in ascending order.
 * - The elements of each diagonal starting from the first column (including the main diagonal) in descending order.
 * Return the sorted matrix.
 *
 * Example:
 * Input: grid = [[3,2,1],[6,5,4],[9,8,7]]
 * Output: [[9,4,1],[6,5,2],[3,8,7]]
 *
 * Approach:
 * - Traverse upper diagonals (excluding main diagonal) and sort each in ascending order.
 * - Traverse lower diagonals (including main diagonal) and sort each in descending order.
 * - Use temporary vectors for each diagonal, sort them, and then reassign to grid.
 *
 * Time Complexity: O(n^2 log n) [Each diagonal sort contributes log n, and total elements are n^2]
 * Space Complexity: O(n^2) [For temporary storage of diagonals]
 */

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Sort upper diagonals (excluding main diagonal) in ascending order
        for (int k = 1; k < n; k++) {
            vector<int> temp;
            for (int i = 0, j = k; i < n && j < n; i++, j++) {
                temp.push_back(grid[i][j]);
            }
            sort(temp.begin(), temp.end());
            for (int i = 0, j = k, f = 0; i < n && j < n; i++, j++, f++) {
                grid[i][j] = temp[f];
            }
        }
        
        // Sort lower diagonals (including main diagonal) in descending order
        for (int k = 0; k < n; k++) {
            vector<int> temp;
            for (int i = k, j = 0; i < n && j < n; i++, j++) {
                temp.push_back(grid[i][j]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            for (int i = k, j = 0, f = 0; i < n && j < n; i++, j++, f++) {
                grid[i][j] = temp[f];
            }
        }
        
        return grid;
    }
};
