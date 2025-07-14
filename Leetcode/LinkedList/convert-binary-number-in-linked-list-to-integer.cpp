// Leetcode Problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Problem no:1290
// Problem Name: Convert Binary Number in a Linked List to Integer
// Level: Easy
// Tags: Linked List, Bit Manipulation

/*
🧠 Problem Summary:
Given `head` which is a reference node to a singly-linked list of 0s and 1s,
representing a binary number, return its decimal equivalent.

Each node stores a single binary digit. Most significant bit is at the head.

📌 Example:
Input: head = [1,0,1]
Output: 5
Explanation: (101)₂ = (5)₁₀

🛠️ Approach:
- Traverse the linked list and store binary digits
- Process vector in reverse, multiplying each bit by its power of 2
- Sum up to get decimal result

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n) (for vector)
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* ptr = head;
        vector<int> temp;
        
        while (ptr != NULL) {
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }

        int cnt = 0, a = 1;
        for (int i = temp.size() - 1; i >= 0; i--, a *= 2) {
            if (temp[i] == 1)
                cnt += a;
        }

        return cnt;
    }
};
