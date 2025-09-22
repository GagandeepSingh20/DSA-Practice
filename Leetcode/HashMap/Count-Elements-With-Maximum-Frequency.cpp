// File: 3005-Count-Elements-With-Maximum-Frequency.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/count-elements-with-maximum-frequency/
 * Problem Number: 3005
 * Problem Name: Count Elements With Maximum Frequency
 * Difficulty: Easy
 * Tags: Array, Hash Table, Counting
 *
 * Problem Summary:
 * Given an integer array nums, return the total frequency of the most frequent element(s).
 * 
 * Example 1:
 * Input: nums = [1,2,2,3,1,4]
 * Output: 4
 * Explanation:
 * Elements 1 and 2 both appear 2 times, which is the maximum frequency. 
 * The total frequency is 2 + 2 = 4.
 *
 * Example 2:
 * Input: nums = [1,2,3,4,5]
 * Output: 1
 *
 * Approach:
 * - Count the frequency of each element using a hash map.
 * - Find the maximum frequency value.
 * - Sum up the frequencies of all elements that appear with the maximum frequency.
 *
 * Time Complexity: O(N), where N = size of nums
 * Space Complexity: O(N) for storing frequencies
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &e: nums){
            mp[e]++;
        }
        int cnt=0,freq=0;
        for(auto & pair: mp){
            if (pair.second>freq){
                freq=pair.second;
                cnt=freq;
            }
            else if(pair.second==freq)cnt+=pair.second;
        }
        return cnt;
    }
};
