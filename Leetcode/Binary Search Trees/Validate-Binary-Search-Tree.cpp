// File: 0098-Validate-Binary-Search-Tree.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/validate-binary-search-tree/
 * Problem Number: 98
 * Problem Name: Validate Binary Search Tree
 * Difficulty: Medium
 * Tags: Binary Search Tree, DFS, Recursion
 *
 * Problem Summary:
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A BST is valid if:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Example:
 * Input: root = [2,1,3]
 * Output: true
 *
 * Approach:
 * - Use a recursive helper `checker` that ensures each node’s value is within a valid range.
 * - Pass down `min` and `max` pointers to ensure BST property holds for all nodes.
 * - If any node violates the rule, return false.
 *
 * Time Complexity: O(N) – visit each node once.
 * Space Complexity: O(H) – recursion stack, where H is the height of the tree.
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
    // Helper function to check BST validity
    bool checker(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return checker(root->left, min, root) && checker(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return checker(root, nullptr, nullptr);
    }
};
