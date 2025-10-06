/*
 * Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * 653. Two Sum IV - Input is a BST
 * Difficulty: Easy
 * Tags: BST, Hashing, DFS
 *
 * Problem Summary:
 * Given the root of a BST and an integer k, return true if there exist two elements
 * in the BST such that their sum equals k.
 *
 * Example:
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 *
 * Approach:
 * - Traverse the tree using DFS.
 * - For each node, check if (k - node->val) is already present in a hash set.
 * - If yes → pair exists → return true.
 * - Otherwise, insert node->val into the set and continue traversal.
 *
 * Time Complexity: O(N)      // visit each node once
 * Space Complexity: O(N)     // store up to N node values in the set
 */

class Solution {
    unordered_set<int>mp;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        if(mp.count(k-root->val))return true;
        mp.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
