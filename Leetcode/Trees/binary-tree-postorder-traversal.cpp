// Leetcode Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Problem Number: 145
// Problem Name: Binary Tree Postorder Traversal
// Level: Easy
// Tags: Tree, DFS, Binary Tree

/*
🧠 Problem Summary:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Postorder Traversal Order: Left → Right → Root

📌 Example:
Input: root = [1,null,2,3]
Output: [3,2,1]

🛠️ Approach:
- Use a helper function to recursively process:
  1. Left subtree
  2. Right subtree
  3. Then the current node
- Store the values in a result vector

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n) due to recursion stack and result storage
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;

        if (root->left != NULL) {
            postorder(root->left, ans);
        }

        if (root->right != NULL) {
            postorder(root->right, ans);
        }

        ans.push_back(root->val);
    }
};
