// GFG Problem: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Problem Name: Top View of Binary Tree
// Level: Medium
// Tags: Tree, Queue, Map, Binary Tree

/*
🧠 Problem Summary:
Given a binary tree, return the top view of it.
The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

📌 Example:
Input:
         1
      /     \
    2        3
     \      / \
      4    5   6

Output: 2 1 3 6

🛠️ Approach:
- Use BFS with a queue of (horizontal distance, node).
- Use a map to store the first node seen at each horizontal distance.
- Traverse level-by-level and insert into the map only if that horizontal distance is not already visited.

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(n), for the queue and map.
*/

/*
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, int> mp;
        queue<pair<int, Node*>> q1;
        q1.push({0, root});
        
        while (!q1.empty()) {
            Node* ptr = q1.front().second;
            int val = q1.front().first;
            q1.pop();
            
            if (mp.find(val) == mp.end()) mp[val] = ptr->data;
            
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
