// GFG Problem: https://www.geeksforgeeks.org/problems/aggressive-cows/1
// Problem Name: Aggressive Cows
// Level: Medium-Hard
// Tags: Binary Search, Greedy, Searching

/*
🧠 Problem Summary:
You are given positions of `n` stalls and `c` cows.
Place the cows in stalls such that the minimum distance between any two cows is maximized.

Return the largest minimum distance possible.

📌 Example:
Input: stalls = [1, 2, 4, 8, 9], c = 3
Output: 3
Explanation: Place cows at stalls 1, 4, and 8. Min distance = 3.

🛠️ Approach:
- Sort the stalls
- Use binary search on answer space (1 to max distance)
- For each mid, check if it's possible to place all cows with that minimum distance
- Greedily place cows in stalls, ensuring the required gap is maintained

🧮 Time Complexity: O(n log(max_dist))
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int c) {
        sort(stalls.begin(), stalls.end());
        int s = 1, e = stalls.back() - stalls.front();
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(stalls, mid, c)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int>& arr, int mid, int c) {
        int cow = 1;
        int last_placed = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last_placed >= mid) {
                last_placed = arr[i];
                cow++;
            }

            if (cow == c) return true;
        }

        return false;
    }
};
