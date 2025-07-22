// Leetcode Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Problem Number: 94
// Problem Name: Binary Tree Inorder Traversal
// Level: Easy
// Tags: Tree, DFS, Binary Tree

/*
🧠 Problem Summary:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Inorder Traversal Order: Left → Root → Right

📌 Example:
Input: root = [1, null, 2, 3]
Output: [1, 3, 2]

🛠️ Approach:
- Use a helper function to perform recursive inorder traversal.
- For each node:
  1. Traverse the left subtree
  2. Visit the current node (add value to answer)
  3. Traverse the right subtree

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n) (due to recursion + result vector)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        inorder(root, ans);
        return ans;
    }

    void inorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;

        if (root->left != NULL) {
            inorder(root->left, ans);
        }

        ans.push_back(root->val);

        if (root->right != NULL) {
            inorder(root->right, ans);
        }
    }
};
