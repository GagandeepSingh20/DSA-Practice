// Leetcode Problem: https://leetcode.com/problems/insert-interval/
// Problem Number: 57
// Problem Name: Insert Interval
// Level: Medium
// Tags: Array, Sorting, Merge Intervals

/*
🧠 Problem Summary:
You are given an array of non-overlapping intervals sorted by their start time,
and a new interval to insert. Merge it into the existing list, ensuring the final list
remains sorted and non-overlapping.

📌 Example:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

🛠️ Approach:
1. Add all intervals that end before `newInterval` starts.
2. Merge overlapping intervals with `newInterval`.
3. Add the merged `newInterval`.
4. Add all intervals that start after `newInterval` ends.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // Step 1: Add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Step 3: Add remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
