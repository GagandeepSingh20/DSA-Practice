/*
Problem: 3679. Minimize Arrivals to Discard
Platform: LeetCode
Difficulty: Medium
Tags: Sliding Window, Hash Map, Queue

Problem Summary:
You are given an integer array `nums`, an integer `w` representing the window size, 
and an integer `m`. For each sliding window of size `w`, 
you may keep at most `m` occurrences of any value. 
If more than `m` occurrences of a value appear in the window, 
the extra arrivals must be discarded.

Return the minimum number of arrivals to discard so that 
every sliding window of size `w` contains at most `m` occurrences of any integer.

Example:
Input: nums = [1,2,1,3,1], w = 4, m = 2
Output: 1

Explanation:
- Window [1,2,1,3] -> all valid
- Next element = 1, would make three 1's in the window, so discard it.

Approach:
- Use a queue to maintain the sliding window with {value, index}.
- Use an unordered_map to track frequency counts of values in the window.
- For each new element:
  - Remove elements that slide out of the window.
  - If the current value appears less than `m` times, keep it.
  - Otherwise, discard it (increment discard counter).
- Return total discarded arrivals.

Time Complexity: O(n), where n = length of nums
Space Complexity: O(w), for the window and hashmap
*/

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& nums, int w, int m) {
        unordered_map<int,int> mp;
        queue<pair<int,int>> q; // {value, index}
        int discard = 0;

        for (int e = 0; e < nums.size(); ++e) {
            // Remove kept items outside the window [e-w+1, e]
            while (!q.empty() && q.front().second < e - w + 1) {
                mp[q.front().first]--;
                q.pop();
            }

            int x = nums[e];
            if (mp[x] < m) {
                mp[x]++;
                q.push({x, e});
            } else {
                discard++;
            }
        }
        return discard;
    }
};
