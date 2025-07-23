// GFG Problem: https://www.geeksforgeeks.org/problems/kth-missing-element3630/1
// Problem Name: Kth Missing Number
// Level: Medium
// Tags: Binary Search, Arrays

/*
🧠 Problem Summary:
Given a sorted array of distinct positive integers starting from 1, and a number `k`,
return the k-th missing number.

📌 Example:
Input: arr = [2, 3, 4, 7, 11], k = 5
Output: 9

🛠️ Approach:
- Use Binary Search to find how many numbers are missing at a given index:
  missing = arr[i] - (i + 1)
- If missing < k, we need to move right
- Otherwise, we move left
- The final answer is `s + k`

🧮 Time Complexity: O(log n)
🧮 Space Complexity: O(1)
*/

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int s = 0, e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return s + k;
    }
};
