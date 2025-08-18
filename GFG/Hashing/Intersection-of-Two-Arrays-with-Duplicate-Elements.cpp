/****************************************************
 * Problem: Intersection of Two Arrays with Duplicate Elements
 * Platform: GeeksforGeeks
 * Difficulty: Easy
 * Tags: Array, Hashing, Two Pointers
 *
 * Problem Statement:
 * Given two arrays A and B. The task is to return the 
 * intersection of both arrays as a vector. 
 * Elements in the result should appear as many times as they 
 * show in both arrays.
 *
 * Example:
 * Input:
 * A = [1, 2, 2, 1]
 * B = [2, 2]
 * Output:
 * [2, 2]
 *
 * Input:
 * A = [4, 9, 5]
 * B = [9, 4, 9, 8, 4]
 * Output:
 * [4, 9]  OR [9, 4]
 *
 * Approach:
 * - Use an unordered_map to count occurrences of elements in A.
 * - Traverse array B, and if an element exists in the map with count > 0:
 *      → Push it into the result.
 *      → Decrease the count in the map.
 *
 * Time Complexity: O(N + M) 
 *   (where N = size of A, M = size of B)
 * Space Complexity: O(N) (for storing frequencies in hashmap)
 ****************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,int> mp;

        // Store frequencies of elements in A
        for (int num : A) {
            mp[num]++;
        }

        // Check B and form intersection
        for (int num : B) {
            if (mp[num] > 0) {
                ans.push_back(num);
                mp[num]--;  // reduce count
            }
        }

        return ans;
    }
};

// Example usage (for local testing only)
/*
int main() {
    Solution sol;
    vector<int> A = {1,2,2,1};
    vector<int> B = {2,2};
    vector<int> res = sol.intersect(A,B);
    for (int x : res) cout << x << " ";
    return 0;
}
*/
