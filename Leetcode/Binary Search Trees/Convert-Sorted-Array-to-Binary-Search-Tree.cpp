/**
 * LeetCode Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Problem Number: 108
 * Problem Name: Convert Sorted Array to Binary Search Tree
 * Difficulty: Easy
 * Tags: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
 *
 * Problem Summary:
 * Given an integer array `nums` where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree (BST).
 *
 * A height-balanced BST is defined as a BST in which the depth of the two subtrees 
 * of every node never differs by more than one.
 *
 * Example:
 * Input: nums = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted.
 *
 * Input: nums = [1,3]
 * Output: [3,1]
 * Explanation: [1,3] is also accepted.
 *
 * Approach:
 * - Use divide and conquer (binary search approach).
 * - Always take the middle element of the array as the root.
 * - Recursively build the left subtree using the left half of the array.
 * - Recursively build the right subtree using the right half of the array.
 *
 * Time Complexity: O(N), where N = number of elements in nums
 * Space Complexity: O(log N) for recursion stack
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
    void tree_builder(vector<int>& nums,TreeNode * root,int start,int end){
        if (start>end )return;
        int mid=(start+end)/2;
        TreeNode * ptr = new TreeNode(nums[mid]);
        if(ptr->val<root->val)root->left=ptr;
        else root->right=ptr;
        tree_builder(nums,ptr,start,mid-1);
        tree_builder(nums,ptr,mid+1,end);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n= nums.size();
        TreeNode * root = new TreeNode(nums[n/2]);
        tree_builder(nums,root,0,n/2-1);
        tree_builder(nums,root,n/2+1,n-1);
        return root;
    }
};
