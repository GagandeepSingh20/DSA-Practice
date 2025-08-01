// GFG Problem: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Problem Name: Bottom View of Binary Tree
// Level: Medium
// Tags: Tree, Queue, Map, Binary Tree

/*
🧠 Problem Summary:
Given a binary tree, return the bottom view of it.
The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

📌 Example:
Input:
          20
         /  \
       8     22
      / \      \
    5   3      25
       / \
     10  14

Output: 5 10 3 14 25

🛠️ Approach:
- Use level-order traversal (BFS) with a queue storing horizontal distance (hd) and node.
- Use a map to store the latest (bottom-most) node at each horizontal distance.
- After traversal, extract values from the map in order of horizontal distance.

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(n), for the queue and map used in traversal.
*/

/* Tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, int> mp;  // horizontal distance -> node data
        queue<pair<int, Node*>> q1;
        q1.push({0, root});
        
        while (!q1.empty()) {
            Node* ptr = q1.front().second;
            int val = q1.front().first;
            q1.pop();
            
            // overwrite to store bottom-most node at this horizontal distance
            mp[val] = ptr->data;
            
            if (ptr->left) q1.push({val - 1, ptr->left});
            if (ptr->right) q1.push({val + 1, ptr->right});
        }
        
        vector<int> ans;
        for (const auto& [key, value] : mp) {
            ans.push_back(value);
        }
        
        return ans;
    }
};
