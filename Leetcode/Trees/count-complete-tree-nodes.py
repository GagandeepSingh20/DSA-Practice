# Leetcode Problem: https://leetcode.com/problems/count-complete-tree-nodes/
# Problem Number: 222
# Problem Name: Count Complete Tree Nodes
# Level: Medium
# Tags: Tree, Binary Tree, DFS, Iterative, Stack

"""
🧠 Problem Summary:
Given the root of a complete binary tree, return the number of the nodes in the tree.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.

📌 Example:
Input: root = [1,2,3,4,5,6]
Output: 6

🛠️ Approach (Iterative DFS):
- Use a stack to traverse the tree.
- For every visited node, increment a counter.
- Push left and right children to the stack.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(h) where h is the height of the tree (stack size)
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        res = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                res += 1
                stack.append(node.left)
                stack.append(node.right)
        return res
