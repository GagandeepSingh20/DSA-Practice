// Leetcode Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Problem Number: 104
// Problem Name: Maximum Depth of Binary Tree
// Level: Easy
// Tags: Tree, Depth-First Search, Recursion

/*
🧠 Problem Summary:
Given the root of a binary tree, return its maximum depth.
The maximum depth is the number of nodes along the longest path from the root down to the farthest leaf node.

📌 Example:
Input: root = [3,9,20,null,null,15,7]
Output: 3

🛠️ Approach:
- Use recursion to calculate the depth of left and right subtrees.
- Return the maximum of both + 1.

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(h), where h is the height of the tree (due to recursive stack).
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return height(root);
    }

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
};
