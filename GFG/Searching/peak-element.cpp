// GFG Problem: https://www.geeksforgeeks.org/problems/peak-element/1
// Problem Name: Peak Element
// Level: Easy
// Tags: Searching, Binary Search

/*
🧠 Problem Summary:
A peak element in an array is the one that is greater than its neighbors.
Given an array, return the **index** of any one peak element.
Array boundaries are considered such that only one neighbor exists at edges.

📌 Example:
Input: arr[] = {1, 2, 3}
Output: 2

📌 Note:
- If multiple peaks exist, return the index of any one of them.
- 0-based indexing

🛠️ Approach:
- Check edge cases separately (first and last elements)
- For the rest, iterate from index 1 to n-2 and check if arr[i] is a peak
- A more optimized approach would use binary search (not used here)

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    int peakElement(vector<int>& arr) {
        if (arr.size() == 1) return 0;

        // Check the first element
        if (arr[0] > arr[1]) return 0;

        // Check the last element
        if (arr[arr.size() - 1] > arr[arr.size() - 2])
            return arr.size() - 1;

        // Check in the middle
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }

        // By problem constraints, there will always be a peak
        return -1;
    }
};
