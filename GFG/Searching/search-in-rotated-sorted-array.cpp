// GFG Problem: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array/0
// Problem Name: Search in Rotated Sorted Array
// Level: Medium
// Tags: Searching, Binary Search

/*
🧠 Problem Summary:
Given a sorted and rotated array `arr[]` of size N and an integer `key`, 
return the index of the key if it's present. Otherwise, return -1.

📌 Example:
Input: N = 9, key = 5
       arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
Output: 0

🛠️ Approach:
- Use a modified binary search:
    1. Check if left half is sorted or right half is sorted.
    2. Narrow search range accordingly based on where the `key` lies.

🧮 Time Complexity: O(logN)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int s = 0, e = arr.size() - 1, mid;

        while (s <= e) {
            mid = s + (e - s) / 2;

            // Key found
            if (arr[mid] == key) return mid;

            // Left half is sorted
            if (arr[mid] >= arr[s]) {
                if (arr[s] <= key && key < arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            // Right half is sorted
            else if (arr[mid] < arr[e]) {
                if (arr[mid] < key && key <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1; // Not found
    }
};
