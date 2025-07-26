// Leetcode Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Problem Number: 102
// Problem Name: Binary Tree Level Order Traversal
// Level: Medium
// Tags: Tree, Breadth-First Search, Queue

/*
🧠 Problem Summary:
Given the root of a binary tree, return the level order traversal of its nodes' values.
(Level by level from left to right)

📌 Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

🛠️ Approach:
- Use a queue for Breadth-First Search (BFS).
- For each level, push all child nodes of the current level into the queue.
- Store the values of each level in a temporary vector and add it to the result.

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(n), for storing nodes in queue and result.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();  // Nodes at current level
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(level);
        }

        return res;
    }
};
