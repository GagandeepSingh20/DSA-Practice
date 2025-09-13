"""
Problem: 701. Insert into a Binary Search Tree
Platform: LeetCode
Difficulty: Medium
Tags: Tree, Binary Search Tree, Recursion, Iteration

Problem Summary:
You are given the root of a binary search tree (BST) and an integer value to insert. 
Insert the value into the BST such that the tree remains a valid BST. 
Return the root of the modified tree.

Example:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]

Approach:
- If the root is None, create a new TreeNode and return it.
- Otherwise, traverse the tree iteratively:
  - If val < current node’s value, go left; if left is None, insert there.
  - If val >= current node’s value, go right; if right is None, insert there.
- Return the root of the modified tree.

Time Complexity: O(h), where h = height of BST
Space Complexity: O(1) (iterative approach)
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        
        ptr = root
        while ptr:
            if ptr.val > val:
                if ptr.left:
                    ptr = ptr.left
                else:
                    ptr.left = TreeNode(val)
                    break
            else:
                if ptr.right:
                    ptr = ptr.right
                else:
                    ptr.right = TreeNode(val)
                    break
        return root
