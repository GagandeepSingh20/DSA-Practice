// GFG Problem: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// Problem Name: Spirally traversing a matrix
// Level: Easy-Medium
// Tags: Matrix, Simulation

/*
🧠 Problem Summary:
Given a matrix of size n x m, return the elements of the matrix in spiral order traversal,
starting from the top-left element.

📌 Example:
Input:
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

🛠️ Approach:
- Use four pointers: `top`, `bottom`, `left`, and `right` to track boundaries.
- Traverse in four directions:
  1. Left to Right (Top row)
  2. Top to Bottom (Right column)
  3. Right to Left (Bottom row)
  4. Bottom to Top (Left column)
- Shrink the boundaries as you move inward in each spiral layer.

🧮 Time Complexity: O(n * m)
🧮 Space Complexity: O(1) (excluding output list)
*/

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &arr) {
        int top = 0, left = 0;
        int right = arr[0].size() - 1;
        int bottom = arr.size() - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Move left to right
            for (int j = left; j <= right; j++) {
                ans.push_back(arr[top][j]);
            }
            top++;

            // Move top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(arr[i][right]);
            }
            right--;

            // Move right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(arr[bottom][j]);
                }
                bottom--;
            }

            // Move bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
