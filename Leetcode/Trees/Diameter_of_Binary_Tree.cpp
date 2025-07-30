// Leetcode Problem: https://leetcode.com/problems/diameter-of-binary-tree/
// Problem Number: 543
// Problem Name: Diameter of Binary Tree
// Level: Easy
// Tags: Tree, Depth-First Search, Binary Tree

"""
🧠 Problem Summary:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes.

📌 Example:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: The longest path is [4,2,1,3] or [5,2,1,3], and it has 3 edges.

🛠️ Approach:
- Use DFS to calculate the height of each subtree.
- At each node, compute the path length through it (left height + right height).
- Track the maximum such value globally.

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
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
    int ans = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
