# Leetcode Problem: https://leetcode.com/problems/subtree-of-another-tree/
# Problem Name: 572. Subtree of Another Tree
# Level: Easy
# Tags: Tree, Depth-First Search, Binary Tree

"""
🧠 Problem Summary:
Given the roots of two binary trees `root` and `subRoot`, check whether `subRoot` is a subtree of `root`.
A subtree of a binary tree `T` is a tree consisting of a node in `T` and all of its descendants.

📌 Example:
Input: 
root = [3,4,5,1,2], subRoot = [4,1,2]
Output: True

root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: False

🛠️ Approach:
- Create a helper function `isIdentical` to compare two trees for structural and value equality.
- Traverse the main tree using recursion.
- At each node, check if the subtree rooted there is identical to `subRoot`.

🧮 Time Complexity: O(m * n), where `m` is the number of nodes in `root` and `n` in `subRoot`
🧮 Space Complexity: O(h), where `h` is the height of the `root` tree (due to recursion)
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isIdentical(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and not subRoot:
            return True
        if not root or not subRoot or root.val != subRoot.val:
            return False
        return (
            self.isIdentical(root.left, subRoot.left) and 
            self.isIdentical(root.right, subRoot.right)
        )

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        if self.isIdentical(root, subRoot):
            return True
        return (
            self.isSubtree(root.left, subRoot) or 
            self.isSubtree(root.right, subRoot)
        )
