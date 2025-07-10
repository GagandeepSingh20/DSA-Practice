// GFG Problem: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Problem Name: Number of Occurrence
// Level: Easy
// Tags: Searching, Binary Search

/*
🧠 Problem Summary:
Given a sorted array of size N and a number X, find the number of occurrences of X in the array.

📌 Example:
Input: N = 7, X = 2, arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4

🛠️ Approach:
- Use a recursive binary search to count occurrences of the target
- Count current match and check left and right sides
- Optimized with boundary checks

🧮 Time Complexity: O(logN) for binary search, but O(N) worst case in repeated matches
🧮 Space Complexity: O(logN) for recursion stack
*/

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        if (arr[0] > target || arr[arr.size() - 1] < target) return 0;
        else if (arr[0] == target && arr[arr.size() - 1] == target) return arr.size();
        
        int s = 0, e = arr.size() - 1;
        return binarysearch(arr, s, e, target);
    }

private:
    int binarysearch(vector<int>& arr, int s, int e, int target) {
        if (s > e) return 0;

        int mid = s + (e - s) / 2;
        int cnt = 0, left = 0, right = 0;

        if (arr[mid] > target) {
            left = binarysearch(arr, s, mid - 1, target);
        } else if (arr[mid] < target) {
            right = binarysearch(arr, mid + 1, e, target);
        } else {
            cnt++;
            left = binarysearch(arr, s, mid - 1, target);
            right = binarysearch(arr, mid + 1, e, target);
        }

        return cnt + left + right;
    }
};
