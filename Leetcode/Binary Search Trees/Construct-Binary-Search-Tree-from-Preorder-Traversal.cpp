/*
🔗 Problem Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
📌 Problem Number: 1008
📚 Name: Construct Binary Search Tree from Preorder Traversal
🟡 Difficulty: Medium
🏷️ Tags: Tree, Binary Search Tree, DFS, Recursion

📝 Problem Summary:
You are given a preorder traversal of a binary search tree (BST). 
Your task is to reconstruct the original BST and return its root.

Example:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Explanation:
The BST constructed is:
        8
       / \
      5   10
     / \    \
    1   7    12

✅ Approach:
- The first element of the preorder list is always the root.
- Elements smaller than root go to the left subtree, larger ones to the right.
- We recursively find the split point where right subtree starts.
- Build left and right subtrees recursively.

⏱️ Time Complexity: O(n^2) in worst case (unbalanced tree).
📦 Space Complexity: O(h) where h is tree height (recursion stack).
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* TreeBuilder(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        // Create the root node from the current preorder segment
        TreeNode* root = new TreeNode(preorder[start]);

        // Find the first element greater than root (right subtree starts here)
        int i;
        for (i = start + 1; i <= end; i++) {
            if (preorder[i] > root->val) break;
        }

        // Recursively build left and right subtrees
        root->left = TreeBuilder(preorder, start + 1, i - 1);
        root->right = TreeBuilder(preorder, i, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return TreeBuilder(preorder, 0, preorder.size() - 1);
    }
};
