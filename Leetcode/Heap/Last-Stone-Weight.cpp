/*
Problem: Last Stone Weight
LeetCode Link: https://leetcode.com/problems/last-stone-weight/
Problem Number: 1046
Difficulty: Easy
Tags: Heap, Priority Queue, Simulation

Summary:
You are given an array of stones' weights. Every turn:
1. Pick the two heaviest stones.
2. Smash them together:
   - If equal, both are destroyed.
   - If different, the smaller one is destroyed and the larger one becomes (larger - smaller).
3. Continue until there is at most one stone left.
Return the weight of the last remaining stone, or 0 if none remain.

Example:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
- Smash 8 and 7 → new stone = 1 → stones = [2,4,1,1,1]
- Smash 4 and 2 → new stone = 2 → stones = [2,1,1,1]
- Smash 2 and 1 → new stone = 1 → stones = [1,1,1]
- Smash 1 and 1 → destroyed → stones = [1]
Result = 1

Approach:
- Use a max-heap (priority_queue in C++) to always extract the two heaviest stones.
- Simulate the smashing process until only one or zero stones remain.
- Return the last stone’s weight or 0.

Time Complexity: O(n log n), where n = number of stones.
Space Complexity: O(n) for the heap.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if (y > x) {
                pq.push(y - x);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};
