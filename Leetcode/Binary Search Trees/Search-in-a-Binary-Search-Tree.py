"""
Problem: Search in a Binary Search Tree
LeetCode Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
Problem Number: 700
Difficulty: Easy
Tags: Binary Search Tree, Recursion, Iteration

Summary:
You are given the root of a binary search tree (BST) and an integer val.  
Find the node in the BST where the node's value equals val and return the subtree rooted with that node.  
If such a node does not exist, return None.

Example:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Approach:
1. Use an iterative approach starting from root.
2. Traverse the tree:
   - If current node's value equals val, return the node.
   - If val is smaller, move to left child; else move to right child.
3. If node is not found, return None.

Time Complexity: O(h), where h is the height of the BST (O(log n) for balanced tree, O(n) for skewed).
Space Complexity: O(1) since we use an iterative approach.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        ptr = root
        while ptr:
            if ptr.val == val:
                return ptr
            elif ptr.val > val:
                ptr = ptr.left
            else:
                ptr = ptr.right
        return None
