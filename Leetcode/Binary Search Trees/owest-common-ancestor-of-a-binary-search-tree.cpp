/*
 * 🧠 Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 📌 Problem Number: 235
 * 📚 Name: Lowest Common Ancestor of a Binary Search Tree
 * 🟢 Difficulty: Medium
 * 🏷️ Tags: Tree, Binary Search Tree, Binary Tree
 * 
 * 📝 Problem Summary:
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes `p` and `q`.
 * The LCA of two nodes p and q is defined as the lowest node in the tree that has both p and q as descendants.
 * 
 * Example:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * ✅ Approach:
 * 1. If the current node is `NULL`, return NULL.
 * 2. If the current node matches `p` or `q`, return it (it’s part of the LCA path).
 * 3. Recursively check in left and right subtrees.
 * 4. If both sides return non-NULL, the current node is the LCA.
 * 5. If only one side is non-NULL, return that side’s result.
 * 
 * ⏱️ Time Complexity: O(N) - Each node is visited once.
 * 📦 Space Complexity: O(H) - Recursion stack, where H is the height of the tree.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL or root is one of p or q
        if (root == NULL || root == p || root == q) return root;

        // Search LCA in left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both sides return a node, root is the LCA
        if (leftLCA && rightLCA) return root;

        // Else, return the non-null child
        return leftLCA ? leftLCA : rightLCA;
    }
};
