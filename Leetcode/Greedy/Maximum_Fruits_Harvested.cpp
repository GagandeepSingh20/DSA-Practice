/*
🔗 Problem Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

🧾 Problem Number & Name: Leetcode 2106 - Maximum Fruits Harvested After at Most K Steps
🟨 Difficulty: Hard
🏷️ Tags: Sliding Window, Greedy, Binary Search, Two Pointers

🧠 Problem Summary:
You're given a list of fruit positions and quantities along a 1D road and a starting position.
You can take at most k steps (left or right) and want to collect the maximum number of fruits possible.

🍌 Each fruit patch is represented as: [position, amount].
You must choose a window of fruit patches such that the total steps needed to visit all patches in the window from startPos is ≤ k.

🧪 Example:
Input:
    fruits = [[2,4],[4,2],[6,1],[8,3],[10,2]], startPos = 5, k = 4
Output:
    7
Explanation:
    One optimal route is: go to 4 → 2 → back to 4 → 6 (4 steps total), collecting 4+2+1 = 7 fruits.

🛠️ Approach:
- Use a sliding window over the sorted fruit positions.
- At each window, calculate the minimum steps needed to go from startPos to both ends.
- If within allowed k steps, update max fruits collected.
- Use a helper `minSteps()` to calculate minimum required steps:
  - All fruits to left or all to right is simple.
  - If both sides, try both left-first and right-first paths.

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)
*/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, total = 0, maxFruits = 0;

        for (int right = 0; right < n; ++right) {
            total += fruits[right][1];  // include current fruit count in window

            // Shrink the window from the left until total steps needed ≤ k
            while (left <= right && 
                   minSteps(fruits, left, right, startPos) > k) {
                total -= fruits[left][1];  // remove fruit at left
                ++left;
            }

            maxFruits = max(maxFruits, total);  // update max
        }

        return maxFruits;
    }

    // Helper to compute min steps needed to reach both ends of the window
    int minSteps(vector<vector<int>>& fruits, int left, int right, int startPos) {
        int leftPos = fruits[left][0];
        int rightPos = fruits[right][0];

        if (rightPos <= startPos) {
            return startPos - leftPos;  // all fruits are to the left
        }
        else if (leftPos >= startPos) {
            return rightPos - startPos;  // all fruits are to the right
        }
        else {
            // Both sides — choose either:
            // 1. Go left first, then to right end: (start - left) + (right - left)
            // 2. Go right first, then to left end: (right - start) + (right - left)
            return min(
                startPos - leftPos + rightPos - leftPos,
                rightPos - startPos + rightPos - leftPos
            );
        }
    }
};
