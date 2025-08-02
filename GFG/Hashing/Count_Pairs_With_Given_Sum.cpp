/*
🔗 Problem Link: https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

🧾 Problem Number & Name: GFG - Count Pairs with Given Sum
🟨 Difficulty: Easy
🏷️ Tags: Hashing, Map, Arrays, Two Sum, Frequency Count

🧠 Problem Summary:
Given an array of integers and a target sum, count the number of pairs that sum up to the target.
The pair (i, j) and (j, i) are considered the same and should not be counted twice.

🧪 Example:
Input:
    N = 4, target = 6
    arr[] = [1, 5, 7, 1]
Output:
    2
Explanation:
    (1,5) and (5,1) form a valid pair, but count as one. The second 1 and 5 also form another pair.

🛠️ Approach:
- Use a hash map to count frequencies of elements.
- For each element, check if (target - element) exists in the map.
- Subtract current element frequency temporarily to avoid counting itself.
- Total count gives the number of valid pairs.

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        map<int, int> mp;
        int cnt = 0;

        // Count frequency of each element
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] += 1;
        }

        // Count valid pairs
        for (int i = 0; i < arr.size(); i++) {
            int x = target - arr[i];
            mp[arr[i]]--;  // Temporarily reduce count to avoid pairing with itself

            if (mp.find(x) != mp.end()) {
                cnt += mp[x];
            }
        }

        return cnt;
    }
};
