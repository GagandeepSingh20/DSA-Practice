"""
Problem: Maximum Width of Binary Tree
LeetCode Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
Problem Number: 662
Difficulty: Medium
Tags: Tree, BFS, Binary Tree

Summary:
Given the root of a binary tree, return the maximum width of the given tree.
The width of a level is defined as the length between the leftmost and rightmost non-null nodes in that level,
including null nodes between them.

Example:
Input: root = [1,3,2,5,3,null,9]
Output: 4

Approach:
1. Use BFS with a queue storing pairs (node, index) where index simulates the position of the node in a complete binary tree.
2. For each level:
   - Get the first and last index in that level.
   - Calculate width = last - first + 1.
   - Normalize indices by subtracting the first index to prevent overflow.
3. Push left child as (normalized * 2 + 1), right child as (normalized * 2 + 2).
4. Keep track of the maximum width.

Time Complexity: O(n) (each node is processed once)
Space Complexity: O(n) (queue for BFS)
"""

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long max_len = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int level = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = q.back().second;
            max_len = max(max_len, (long long)(last - first + 1));

            for (int i = 0; i < level; i++) {
                auto [node, index] = q.front();
                q.pop();
                unsigned long long normalized = index - first; // Normalize to prevent overflow

                if (node->left) q.push({node->left, normalized * 2 + 1});
                if (node->right) q.push({node->right, normalized * 2 + 2});
            }
        }

        return (int)max_len;
    }
};
