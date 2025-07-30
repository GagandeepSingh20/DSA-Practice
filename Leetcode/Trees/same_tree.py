# Leetcode Problem: https://leetcode.com/problems/same-tree/
# Problem Name: 100. Same Tree
# Level: Easy
# Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree

"""
🧠 Problem Summary:
Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

📌 Example:
Input: 
p = [1,2,3], q = [1,2,3]
Output: True

p = [1,2], q = [1,null,2]
Output: False

🛠️ Approach:
- Recursively compare each node in both trees.
- If both nodes are `None`, return True.
- If one is `None` or values differ, return False.
- Recursively check left and right subtrees.

🧮 Time Complexity: O(N) where N is the number of nodes
🧮 Space Complexity: O(H) for recursion stack (H = height of the tree)
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
