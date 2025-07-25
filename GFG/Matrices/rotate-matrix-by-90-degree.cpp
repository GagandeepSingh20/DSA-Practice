// GFG Problem: https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
// Problem Name: Rotate by 90 degree
// Level: Medium
// Tags: Matrix, Simulation

/*
🧠 Problem Summary:
Given a square matrix `mat[][]` of size N x N, rotate it by 90 degrees in the anti-clockwise direction in-place.

📌 Example:
Input:
N = 3
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
Output:
[[3, 6, 9],
 [2, 5, 8],
 [1, 4, 7]]

🛠️ Approach:
1. First transpose the matrix (swap mat[i][j] with mat[j][i]).
2. Then reverse each column to achieve a 90-degree anti-clockwise rotation.

🧮 Time Complexity: O(N^2)
🧮 Space Complexity: O(1) – done in-place
*/

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each column (top to bottom)
        for (int j = 0; j < n; j++) {
            for (int i = 0, k = n - 1; i < k; i++, k--) {
                swap(mat[i][j], mat[k][j]);
            }
        }
    }
};
