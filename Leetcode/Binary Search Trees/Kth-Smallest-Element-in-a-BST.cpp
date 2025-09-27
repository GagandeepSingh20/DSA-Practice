// File: 0230-Kth-Smallest-Element-in-a-BST.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Problem Number: 230
 * Problem Name: Kth Smallest Element in a BST
 * Difficulty: Medium
 * Tags: Binary Search Tree, DFS, Inorder Traversal
 *
 * Problem Summary:
 * Given the root of a Binary Search Tree and an integer k, return the kth smallest 
 * value (1-indexed) among all the values of the nodes in the tree.
 *
 * Example:
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 * Approach:
 * - Perform an inorder traversal (Left → Root → Right) which returns nodes in sorted order.
 * - Store all node values in a vector during traversal.
 * - Return the (k-1)th element from this vector (since vector is 0-indexed).
 *
 * Time Complexity: O(N) – visiting each node once.
 * Space Complexity: O(N) – storing all nodes in a vector.
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
    // Helper function for inorder traversal
    void inorder_traverse(TreeNode* root, vector<int> &v1) {
        if (root == nullptr) return;
        if (root->left) inorder_traverse(root->left, v1);
        v1.push_back(root->val);
        if (root->right) inorder_traverse(root->right, v1);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v1;
        inorder_traverse(root, v1);
        return v1[k - 1]; // k is 1-indexed
    }
};
