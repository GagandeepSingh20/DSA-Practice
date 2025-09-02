/*
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Problem Number: 105
Problem Name: Construct Binary Tree from Preorder and Inorder Traversal
Difficulty: Medium
Tags: Tree, Binary Tree, DFS

Problem Summary:
Given two integer arrays preorder and inorder, where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Approach:
- Use preorder to identify the root of the tree.
- Use inorder to determine the boundaries of left and right subtrees.
- Recursively build left and right subtrees using index ranges.
- Maintain a pointer for the current index in preorder (pidx).

Time Complexity: O(n^2) in worst case (due to linear search in inorder for each node).
Space Complexity: O(n) for recursion stack.
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
    int search(vector<int>& inorder, int val, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    TreeNode* tree_builder(vector<int>& preorder, vector<int>& inorder, int &pidx, int l, int r) {
        if (l > r) return NULL;

        TreeNode* root = new TreeNode(preorder[pidx]);
        int idx = search(inorder, preorder[pidx], l, r);
        pidx++;

        root->left = tree_builder(preorder, inorder, pidx, l, idx - 1);
        root->right = tree_builder(preorder, inorder, pidx, idx + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pidx = 0;
        return tree_builder(preorder, inorder, pidx, 0, inorder.size() - 1);
    }
};
