// Leetcode Problem: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
// Problem no: 2410 
// Problem Name: Maximum Matching of Players With Trainers
// Level: Medium
// Tags: Greedy, Sorting, Two Pointers, Arrays

/*
🧠 Problem Summary:
You are given two integer arrays: players and trainers.
Each player has a strength, and each trainer has a capacity.
A player can be matched with a trainer only if the trainer's capacity >= player's strength.

Return the maximum number of matchings between players and trainers.

📌 Example:
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2

🛠️ Approach:
- Sort both arrays
- Use two pointers to greedily match players to the smallest trainer that can accommodate them
- Skip trainers who are too weak

🧮 Time Complexity: O(n log n + m log m)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int i=players.size()-1;
        int j=trainers.size()-1;
        int cnt=0;
        while(i>=0&&j>=0){
            if(players[i]<=trainers[j]){
                cnt++;
                i--;
                j--;
            }
            else if(players[i]>trainers[j])i--;
        }
        return cnt;     
    }
};
