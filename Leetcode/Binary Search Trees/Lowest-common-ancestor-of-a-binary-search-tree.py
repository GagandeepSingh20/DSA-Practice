"""
🧠 Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
📌 Problem Number: 235
📚 Name: Lowest Common Ancestor of a Binary Search Tree
🟢 Difficulty: Medium
🏷️ Tags: Tree, Binary Search Tree, Binary Tree

📝 Problem Summary:
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes `p` and `q`.
The LCA of two nodes p and q is defined as the lowest node in the tree that has both p and q as descendants.

Example:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

✅ Approach (Iterative using BST property):
1. Traverse the tree starting from the root.
2. If current node value is greater than both `p` and `q`, move to the left subtree.
3. If current node value is smaller than both, move to the right subtree.
4. If current node lies between `p` and `q` or equals one of them, it's the LCA.

⏱️ Time Complexity: O(H) - where H is the height of the tree.
📦 Space Complexity: O(1) - iterative approach, no extra recursion stack.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Edge case: if root is None or matches p or q
        if root is None or root == p or root == q:
            return root
        
        ptr = root
        while ptr:
            # If current node is the split point
            if (ptr.val >= p.val and ptr.val <= q.val) or (ptr.val >= q.val and ptr.val <= p.val):
                return ptr
            # If both nodes are smaller, move left
            elif ptr.val > p.val and ptr.val > q.val:
                ptr = ptr.left
            # If both nodes are larger, move right
            else:
                ptr = ptr.right
        
        return None

