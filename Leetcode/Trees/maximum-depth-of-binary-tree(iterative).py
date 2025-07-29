# Leetcode Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Problem Number: 104
# Problem Name: Maximum Depth of Binary Tree
# Level: Easy
# Tags: Tree, Depth-First Search, Stack, Iterative, Recursion

"""
🧠 Problem Summary:
Given the `root` of a binary tree, return its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

📌 Example:
Input: root = [3,9,20,None,None,15,7]
Output: 3

🛠️ Approach (Iterative DFS):
- Use a stack to simulate recursion. Each stack entry stores a node and its depth.
- Track the maximum depth encountered while traversing.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n) – worst case if tree is skewed
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Iterative DFS approach using stack
        stack = [[root, 1]]
        res = 0

        while stack:
            node, depth = stack.pop()
            if node:
                res = max(res, depth)
                stack.append([node.left, depth + 1])
                stack.append([node.right, depth + 1])
        return res
