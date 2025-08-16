/*
Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Problem Number: 114
Difficulty: Medium
Tags: Linked List, Stack, Tree, Depth-First Search, Binary Tree

Problem Summary:
Given the root of a binary tree, flatten the tree into a "linked list":
- The "linked list" should use the same TreeNode class, where the right child points to the next node.
- The left child of all nodes must be set to NULL.
- The linked list should be in the same order as a **preorder traversal** of the binary tree.

Example:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Approach:
1. Perform a preorder traversal of the tree and store all nodes in a vector.
2. Iterate over this vector and connect nodes sequentially:
   - Set left child = NULL.
   - Set right child = next node in vector.
3. The last node should point to NULL.

Time Complexity: O(N) – each node is visited once.
Space Complexity: O(N) – storing preorder nodes in a vector.
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
    void preorder(TreeNode* root, vector<TreeNode*>& temp) {
        if (root == NULL) return;
        temp.push_back(root);
        // left subtree
        preorder(root->left, temp);
        // right subtree
        preorder(root->right, temp);
    }
    
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        vector<TreeNode*> temp;
        preorder(root, temp);
        for (int i = 0; i < temp.size(); i++) {
            temp[i]->left = NULL;
            if (i < temp.size() - 1) temp[i]->right = temp[i + 1];
            else temp[i]->right = NULL;
        }
    }
};
