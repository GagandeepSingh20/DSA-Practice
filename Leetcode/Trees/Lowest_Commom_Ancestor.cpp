/*
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Problem Number: 236
 * Title: Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Tags: Tree, Binary Tree, DFS, Recursion
 *
 * Problem Summary:
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * The LCA is the lowest node that has both p and q as descendants (a node can be a descendant of itself).
 *
 * Example:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 *
 * Approach:
 * - Use recursion:
 *   1. If root is NULL, return NULL.
 *   2. If root matches either p or q, return root.
 *   3. Recursively find LCA in left and right subtrees.
 *   4. If both sides return non-null, root is LCA.
 *   5. If one side is NULL, return the other side.
 *
 * Time Complexity: O(N) where N = number of nodes (DFS traversal)
 * Space Complexity: O(H) where H = height of the tree (recursion stack)
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
        if (root==NULL||root==p||root==q)return root;
        TreeNode* left_LCA=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_LCA=lowestCommonAncestor(root->right,p,q);
        if(right_LCA==NULL)return left_LCA;
        else if (left_LCA==NULL)return right_LCA;
        else return root;
    }
};
