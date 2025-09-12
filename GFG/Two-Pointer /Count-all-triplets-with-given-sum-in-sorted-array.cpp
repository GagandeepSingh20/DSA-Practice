/*
 * Problem: Count all triplets with given sum in sorted array
 * Platform: GeeksforGeeks
 * Difficulty: Medium
 * Tags: Two Pointers, Sorting, Hashing
 *
 * Problem Summary:
 * Given a sorted array of integers and a target value, 
 * count the number of unique triplets in the array 
 * whose sum equals the target.
 *
 * Example:
 * Input: arr = [1, 2, 3, 4, 5], target = 9
 * Output: 2
 * Explanation:
 * Triplets are (1,3,5) and (2,3,4).
 *
 * Approach:
 * - Use a two-pointer method for each fixed element.
 * - Move `j` forward if the sum is too small.
 * - Move `k` backward if the sum is too large.
 * - When a valid triplet is found, count duplicates 
 *   for both `arr[j]` and `arr[k]`.
 * - Carefully handle the case when both sides have the same value.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int countTriplets(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        
        long long cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            int j = i + 1, k = arr.size() - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    int left = arr[j], right = arr[k];
                    int l_cnt = 0, r_cnt = 0;
                    
                    while (j <= k && arr[j] == left) {
                        l_cnt++;
                        j++;
                    }
                    while (k >= j && arr[k] == right) {
                        r_cnt++;
                        k--;
                    }
                    
                    if (left == right) cnt += (1LL * l_cnt * (l_cnt - 1)) / 2;
                    else cnt += 1LL * l_cnt * r_cnt;
                }
            }
        }
        return cnt;
    }
};
