// File: 0450-Delete-Node-in-a-BST.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/delete-node-in-a-bst/
 * Problem Number: 450
 * Problem Name: Delete Node in a BST
 * Difficulty: Medium
 * Tags: Binary Tree, BST, Recursion
 *
 * Problem Summary:
 * Given a root node of a Binary Search Tree (BST) and a key, delete the node 
 * with the given key and return the root of the modified BST. 
 * The tree should maintain the BST property after deletion.
 *
 * Example:
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 *
 * Approach:
 * - Traverse the tree to find the node with the given key.
 * - If found:
 *   1. If it has no left child → replace it with its right subtree.
 *   2. If it has no right child → replace it with its left subtree.
 *   3. If it has both children → replace its value with its inorder successor (minimum node in right subtree) and delete that successor.
 *
 * Time Complexity: O(H), where H is the height of the tree.
 * Space Complexity: O(H) due to recursion stack.
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
    // Helper function to find the inorder successor (smallest node in right subtree)
    TreeNode* getIS(TreeNode* root) {
        while (root != nullptr && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Case 1: Node with only right child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: Node with only left child
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Node with two children
            else {
                TreeNode* IS = getIS(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }
        return root;
    }
};
