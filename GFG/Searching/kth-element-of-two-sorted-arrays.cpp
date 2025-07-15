// GFG Problem: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Problem Name: K-th element of two sorted Arrays
// Level: Medium
// Tags: Searching, Two Pointers, Arrays

/*
🧠 Problem Summary:
Given two sorted arrays `a[]` and `b[]` of size `n` and `m` respectively and an integer `k`,
find the k-th element in the merged sorted array formed from both.

You should not actually merge the arrays. Try to do it in O(k) time.

📌 Example:
Input: a[] = {2, 3, 6, 7, 9}, b[] = {1, 4, 8, 10}, k = 5
Output: 4

🛠️ Approach:
- Use two pointers to virtually merge the two arrays
- Move pointers `i` and `j` until the (k-1) smallest elements are skipped
- Then take the next smallest element between a[i] and b[j]

🧮 Time Complexity: O(k)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i = 0, j = 0;

        // Skip k-1 smallest elements
        while (i < a.size() && j < b.size() && k > 1) {
            if (a[i] < b[j]) i++;
            else j++;
            k--;
        }

        // Now the k-th element is the smaller of a[i] or b[j]
        if (i < a.size() && j < b.size()) return min(a[i], b[j]);
        else if (i < a.size()) return a[i + k - 1];
        return b[j + k - 1];
    }
};
