// GFG Problem: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Problem Name: Search in a Matrix
// Level: Medium
// Tags: Matrix, Binary Search

/*
🧠 Problem Summary:
Given a matrix `mat[][]` of dimensions N x M where every row and column is sorted in increasing order,
check whether a given number X is present in the matrix or not.

📌 Example:
Input:
N = 3, M = 3
mat[][] = [[3, 30, 38], 
           [44, 52, 54], 
           [57, 60, 69]]
X = 62
Output: 0

🛠️ Approach:
- Iterate through each row to find the one where X can possibly lie (based on row's first and last elements).
- Apply binary search within that row to locate the element.

🧮 Time Complexity: O(N * log M), where N = number of rows and M = number of columns.
🧮 Space Complexity: O(1)
*/

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int i = 0;
        int n = mat.size();
        
        while (i < n) {
            int m = mat[i].size();
            if (mat[i][0] <= x && x <= mat[i][m - 1]) {
                // Binary Search in this row
                int s = 0, e = m - 1;
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
