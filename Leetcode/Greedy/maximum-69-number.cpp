// """
// Problem Link: https://leetcode.com/problems/maximum-69-number/
// Problem Number: 1323
// Difficulty: Easy
// Tags: Math, Greedy, String

// Problem Summary:
// You are given a positive integer num consisting only of digits 6 and 9.
// Return the maximum number you can get by changing at most one digit (6 → 9).

// Example:
// Input: num = 9669
// Output: 9969

// Input: num = 9996
// Output: 9999

// Approach:
// 1. Convert the number to a string.
// 2. Traverse from left to right and change the **first '6'** to '9'.
//    - This maximizes the number since leftmost digits have higher place value.
// 3. If there is no '6', return the original number.
// 4. Convert back to integer and return.

// Time Complexity: O(d), where d = number of digits.
// Space Complexity: O(d) due to string conversion.
// """

class Solution {
public:
    int maximum69Number (int num) {
        stack<int> s1;
        int n=num;
        while(n>0){
            s1.push(n%10);
            n/=10;
        }
        n=0;
        bool flag = false;
        while(!s1.empty()){
            if (flag==false and s1.top()==6){
                n=n*10+9;
                flag= true;
            }
            else n=n*10+s1.top();
            s1.pop();
        }
        return n;
    }
};
