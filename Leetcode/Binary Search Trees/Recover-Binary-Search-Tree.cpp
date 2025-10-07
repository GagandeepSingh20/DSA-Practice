/*
🔗 Problem Link: https://leetcode.com/problems/recover-binary-search-tree/
📌 Problem Number: 99
📚 Name: Recover Binary Search Tree
🔴 Difficulty: Hard
🏷️ Tags: Tree, Binary Search Tree, DFS, Inorder Traversal

📝 Problem Summary:
Two nodes of a Binary Search Tree (BST) are swapped by mistake.
Your task is to recover the tree without changing its structure.

Example:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation:
The swapped nodes are 1 and 3. Fixing them recovers the BST.

✅ Approach:
- In a BST, an inorder traversal yields a sorted sequence.
- If two nodes are swapped, the sorted order is violated at one or two points.
- Perform inorder traversal:
  - Detect the first violation: `first = prev`
  - Detect the second violation: `second = current`
- After traversal, swap the values of `first` and `second` to fix the BST.

⏱️ Time Complexity: O(n) – inorder traversal of all nodes.
📦 Space Complexity: O(h) – recursion stack, where h is the height of the tree.
*/

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* prev = nullptr;  // previous node in inorder traversal
    TreeNode* first = nullptr; // first misplaced node
    TreeNode* second = nullptr; // second misplaced node

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect swapped nodes
        if (prev && prev->val > root->val) {
            if (!first) first = prev; // first violation
            second = root;            // second violation (may update twice)
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
