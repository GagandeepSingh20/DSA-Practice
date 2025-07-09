// Leetcode Problem: https://leetcode.com/problems/triangle/
// Problem Number: 120
// Problem Name: Triangle
// Level: Medium
// Tags: Dynamic Programming, Array

/*
🧠 Problem Summary:
Given a triangle array, return the minimum path sum from top to bottom.
At each step, you may move to adjacent numbers on the row below.

📌 Example:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: 2 + 3 + 5 + 1 = 11

🛠️ Approach:
- Bottom-up Dynamic Programming
- Start from the second-last row, update each element to be the sum of itself and the min of the two elements just below it.

🧮 Time Complexity: O(n²)
🧮 Space Complexity: O(1) (in-place)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        if(arr.size()==1)return arr[0][0];
        for(int i=arr.size()-2;i>=0;i--){
          for(int j=0;j<arr[i].size();j++)
          {   
            arr[i][j]+=min(arr[i+1][j],arr[i+1][j+1]);
          }
        } 
        return arr[0][0];
    }  
};
