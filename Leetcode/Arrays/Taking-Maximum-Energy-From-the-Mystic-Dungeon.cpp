/*
🔗 Problem Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
📌 Problem Number: 3147
📚 Name: Taking Maximum Energy From the Mystic Dungeon
🟠 Difficulty: Medium
🏷️ Tags: Dynamic Programming, Array, Greedy

📝 Problem Summary:
You are given an integer array `energy` of length `n`, and an integer `k`.
You start from any index `i`, and from that point, you can jump to index `i + k`, `i + 2k`, etc., 
collecting energy from each position you land on.

Return the maximum total energy you can collect by choosing an optimal starting point.

Example:
Input: energy = [5,2,-10,-5,1], k = 3
Output: 3
Explanation:
Start from index 1 → collect 2 + 1 = 3 (maximum possible)

✅ Approach:
- Traverse the array in reverse.
- For each index `i`, add the energy from index `i + k` (if valid).
- After this transformation, `energy[i]` holds the total sum achievable starting from index `i`.
- The answer is the maximum value in the modified array.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        // Dynamic propagation of energy values backwards
        for (int i = energy.size() - 1; i >= 0; i--) {
            if (i - k >= 0) 
                energy[i - k] += energy[i];
        }

        // Find the maximum collected energy
        int maxEnergy = energy[0];
        for (int i = 1; i < energy.size(); i++)
            if (maxEnergy < energy[i]) 
                maxEnergy = energy[i];

        return maxEnergy;
    }
};
