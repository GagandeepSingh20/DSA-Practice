// Leetcode Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Problem Number: 144
// Problem Name: Binary Tree Preorder Traversal
// Level: Easy
// Tags: Tree, DFS, Binary Tree

/*
🧠 Problem Summary:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Preorder Traversal Order: Root → Left → Right

📌 Example:
Input: root = [1,null,2,3]
Output: [1,2,3]

🛠️ Approach:
- Start from the root node
- Visit and store the current node value
- Recursively process the left subtree, then the right subtree
- Use a helper function `preorder()` to assist the recursive logic

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n) for recursion stack + result vector
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        ans.push_back(root->val);
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;

        if (root->left != NULL) {
            ans.push_back(root->left->val);
            preorder(root->left, ans);
        }

        if (root->right != NULL) {
            ans.push_back(root->right->val);
            preorder(root->right, ans);
        }
    }
};
