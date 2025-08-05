/*
🔗 Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
🧠 Problem Number: 124
📌 Problem Name: Binary Tree Maximum Path Sum
💪 Difficulty: Hard
🏷️ Tags: Tree, DFS, Recursion, Dynamic Programming
*/
"""
📝 Problem Summary:
Given the root of a binary tree, return the maximum path sum. 
A path is any sequence of nodes from some starting node to any node in the tree 
along the parent-child connections. The path must contain at least one node 
and does not need to go through the root.

📊 Example:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 → 20 → 7.

🔍 Approach:
- Use DFS to compute the max path sum at each node.
- For each node, compute the max sum from left and right subtrees.
- Ignore negative paths by capping them at 0.
- Track the global max path sum using a reference variable.
- Return the max one-sided path (for parent recursion).

⏱️ Time Complexity: O(n), where n is the number of nodes in the tree.
💾 Space Complexity: O(h), where h is the height of the tree (recursion stack).

"""

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;

            int leftGain = max(dfs(node->left), 0);
            int rightGain = max(dfs(node->right), 0);

            // Path including both left and right
            maxSum = max(maxSum, node->val + leftGain + rightGain);

            // Return max one-sided path
            return node->val + max(leftGain, rightGain);
        };

        dfs(root);
        return maxSum;
    }
};
