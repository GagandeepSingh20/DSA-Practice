/*
 * Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * Problem Number: 1493
 * Problem Name: Longest Subarray of 1's After Deleting One Element
 * Difficulty: Medium
 * Tags: Sliding Window, Array, Two Pointers
 *
 * Problem Summary:
 * Given a binary array nums, you must delete exactly one element from the array.
 * Return the size of the longest non-empty subarray containing only 1's in the resulting array.
 *
 * Example:
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the 0, the array becomes [1,1,1] with length 3.
 *
 * Approach:
 * 1. Use a sliding window approach to maintain at most one zero in the window.
 * 2. Expand the window by moving `right` pointer.
 * 3. If more than one zero appears, shrink from the left until only one zero remains.
 * 4. Keep track of the maximum window size.
 * 5. Return max length after considering deletion of one element.
 *
 * Time Complexity: O(n) — each element is visited at most twice.
 * Space Complexity: O(1) — constant extra space.
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_cnt=0,non=0;
        map<int,int> mp;
        int key=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)mp[key]+=1;
            else {
                non++;
                key++;
            }
        }
        
        auto it=mp.begin(),prev=mp.begin();
        if(mp.size()==0)return 0;
        if(mp.size()==1){
            if(non>0)return prev->second;
            return prev->second-1;
        }
        it++;
        for(;it!=mp.end();it++,prev++){
            int temp;
            if(it->first==prev->first+1)temp=it->second+prev->second;
            else temp=prev->second;
            max_cnt=max(max_cnt,temp);

        }
        return max_cnt;
    }
};
