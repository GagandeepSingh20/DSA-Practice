// GFG Problem: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Problem Name: Search in a row-wise sorted matrix
// Level: Medium
// Tags: Matrix, Binary Search

/*
🧠 Problem Summary:
You are given a matrix `mat[][]` of size N x M where every row is sorted in increasing order.
You are also given an integer X. You need to search the element X in the matrix.

📌 Example:
Input:
N = 3, M = 3, X = 62
mat[][] = [[3, 30, 38],
           [44, 52, 54],
           [57, 60, 69]]
Output: 0

🛠️ Approach:
- Traverse each row.
- If X lies within the range of a row, perform binary search in that row.
- If found, return true.

🧮 Time Complexity: O(N * log M) – N rows, binary search on M columns.
🧮 Space Complexity: O(1)
*/

class Solution {
  public:
    // Function to search a given number in row-wise sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int i = 0;
        int n = mat.size();

        while (i < n) {
            int m = mat[i].size();

            // Check if x could be in this row
            if (mat[i][0] <= x && mat[i][m - 1] >= x) {
                int s = 0, e = m - 1;

                // Binary search in the current row
                while (s <= e) {
                    int mid = s + (e - s) / 2;

                    if (mat[i][mid] == x) return true;
                    else if (mat[i][mid] < x) s = mid + 1;
                    else e = mid - 1;
                }
            }
            i++;
        }

        return false;
    }
};
