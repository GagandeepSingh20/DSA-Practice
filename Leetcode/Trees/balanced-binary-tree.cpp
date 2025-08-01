// LeetCode Problem: https://leetcode.com/problems/balanced-binary-tree/
// Problem Number: 110
// Problem Name: Balanced Binary Tree
// Difficulty: Easy
// Tags: Tree, Depth-First Search, Binary Tree

/*
🧠 Problem Summary:
Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differs by more than one.

📌 Example:
Input: root = [3,9,20,null,null,15,7]
Output: true

🛠️ Approach:
- Use a helper function `isHeight` to calculate the height of subtrees.
- For each node, check the height difference between left and right subtree.
- Recurse for left and right subtrees to check balance condition.

🧮 Time Complexity: O(n^2) in the worst case due to repeated subtree height calculation.
🧮 Space Complexity: O(h) where h is the height of the tree (for recursion stack).
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
    int isHeight(TreeNode* root){
        if (root == NULL) return 0;
        int left = isHeight(root->left);
        int right = isHeight(root->right);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int left_h = isHeight(root->left);
        int right_h = isHeight(root->right);

        if (abs(left_h - right_h) > 1) return false;

        bool f1 = isBalanced(root->left);
        bool f2 = isBalanced(root->right);
        return f1 && f2;  
    }
};
