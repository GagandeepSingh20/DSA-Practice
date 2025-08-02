# LeetCode Problem: https://leetcode.com/problems/symmetric-tree/
# Problem Number: 101
# Problem Name: Symmetric Tree
# Difficulty: Easy
# Tags: Tree, DFS, BFS, Binary Tree

'''
🧠 Problem Summary:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

📌 Example:
Input: root = [1,2,2,3,4,4,3]
Output: True

🛠️ Approach:
1. Define a helper function `isMirror` that compares two subtrees.
2. Two trees are a mirror of each other if:
   - Their root values are equal.
   - The left subtree of one is a mirror of the right subtree of the other and vice versa.
3. Call `isMirror(root.left, root.right)` from the main function.

🧮 Time Complexity: O(n), where n is the number of nodes in the tree.
🧮 Space Complexity: O(h), where h is the height of the tree due to recursion stack.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isMirror(self, t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return (
            t1.val == t2.val and
            self.isMirror(t1.left, t2.right) and
            self.isMirror(t1.right, t2.left)
        )

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)
