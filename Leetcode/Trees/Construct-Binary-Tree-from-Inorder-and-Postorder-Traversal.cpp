"""
Problem: Construct Binary Tree from Inorder and Postorder Traversal
LeetCode Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Problem Number: 106
Difficulty: Medium
Tags: Tree, Binary Tree, Recursion, Divide and Conquer

Summary:
You are given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree. Construct and return the binary tree.

Example:
Input:
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Output:
[3,9,20,null,null,15,7]

Approach:
1. The last element in postorder is the root.
2. Find the root's index in inorder to separate left and right subtrees.
3. Recursively build the right subtree first (because in postorder, right comes before left when we traverse backwards).
4. Recursively build the left subtree.
5. Base condition: if l > r, return NULL.

Time Complexity: O(n^2) (because searching in inorder array takes O(n) for each node)
Space Complexity: O(n) (for recursion stack)
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
    // Helper function to search index of value in inorder array
    int search(vector<int>& inorder, vector<int>& postorder, int val, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    // Recursive function to construct the tree
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &pidx, int l, int r) {
        if (l > r) return NULL;

        // Current root is the last element in postorder
        TreeNode* root = new TreeNode(postorder[pidx]);

        int idx = search(inorder, postorder, postorder[pidx], l, r);
        pidx--;

        // Build right subtree first
        root->right = helper(inorder, postorder, pidx, idx + 1, r);
        // Then build left subtree
        root->left = helper(inorder, postorder, pidx, l, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pidx = inorder.size() - 1;
        return helper(inorder, postorder, pidx, 0, inorder.size() - 1);
    }
};
