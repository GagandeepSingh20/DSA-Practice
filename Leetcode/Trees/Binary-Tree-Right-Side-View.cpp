// Leetcode Problem: https://leetcode.com/problems/binary-tree-right-side-view/
// Problem Number: 199. Binary Tree Right Side View
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree

/*
🧠 Problem Summary:
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values
of the nodes you can see ordered from top to bottom.

📌 Example:
Input:       1
           /   \
          2     3
           \     \
            5     4
Output: [1,3,4]

🛠️ Approach:
- Use level order traversal (BFS) with a queue.
- Traverse right child before left child at each level.
- Record the first node at each level (rightmost).

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q1;
        q1.push(root);
        ans.push_back(root->val);
        q1.push(NULL);

        while (!q1.empty()) {
            TreeNode* ptr = q1.front();
            q1.pop();

            if (ptr == NULL) {
                q1.push(NULL);
                if (q1.empty() || q1.front() == NULL) break;
                ptr = q1.front();
                ans.push_back(ptr->val);
            }

            if (ptr->right) q1.push(ptr->right);
            if (ptr->left)  q1.push(ptr->left);
        }

        return ans;
    }
};
