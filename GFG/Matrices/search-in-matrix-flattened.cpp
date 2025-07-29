// GFG Problem: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Problem Name: Search in a Matrix (Flattened Binary Search)
// Level: Medium
// Tags: Matrix, Binary Search

/*
🧠 Problem Summary:
Given a matrix with N rows and M columns where each row and each column is sorted in increasing order,
you need to determine whether a given value X exists in the matrix.

📌 Example:
Input:
N = 3, M = 3, X = 62
mat[][] = [[3, 30, 38],
           [44, 52, 54],
           [57, 60, 69]]
Output: 0

🛠️ Approach (Flattened Binary Search):
- Treat the 2D matrix as a virtual 1D sorted array of size N * M.
- Apply binary search using index conversion: `row = mid / columns`, `col = mid % columns`.

🧮 Time Complexity: O(log(N*M))
🧮 Space Complexity: O(1)
*/

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        if (mat.empty() || mat[0].empty()) return false;

        int row = mat.size();
        int col = mat[0].size();
        int low = 0, high = row * col - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / col;
            int c = mid % col;
            int midval = mat[r][c];

            if (midval == x) return true;
            else if (midval < x) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
