/*************************************************************
💡 Problem: Set Matrix Zeroes
🌐 Platform: GeeksforGeeks
🔗 Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1
🧠 Category: Matrix, Data Structures
🎯 Difficulty: Medium
**************************************************************/

/*
📝 Problem Statement:
Given a matrix of size N x M. If an element in the matrix is 0,
you must set its entire row and column to 0. Do it in-place.

📌 Example 1:
Input:
N = 3, M = 3
matrix[][] = {{1,2,3},
              {4,0,6},
              {7,8,9}}

Output:
1 0 3
0 0 0
7 0 9

📌 Constraints:
1 ≤ N, M ≤ 100
0 ≤ matrix[i][j] ≤ 10^5

📦 Expected Time Complexity: O(N*M)
📦 Expected Space Complexity: O(N*M) (This version uses extra stack space)

💡 Approach:
1. Traverse the matrix and store all indices where mat[i][j] == 0 using a stack.
2. For every such index, set its entire row and column to 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        stack<pair<int, int>> s1;

        // Step 1: Store the positions of zero elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    s1.push({i, j});
            }
        }

        // Step 2: For each position, set entire row and column to zero
        while (!s1.empty()) {
            int row = s1.top().first;
            int col = s1.top().second;
            s1.pop();

            for (int i = 0; i < n; i++) {
                mat[i][col] = 0;
            }
            for (int j = 0; j < m; j++) {
                mat[row][j] = 0;
            }
        }
    }
};
