// GFG Problem: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Problem Name: Left View of Binary Tree
// Level: Easy
// Tags: Tree, Queue, Binary Tree, BFS

/*
🧠 Problem Summary:
Given a Binary Tree, return a list containing elements of the left view of the Binary Tree.
The left view of a Binary Tree is a set of nodes visible when the tree is viewed from the left side.

📌 Example:
Input:
       1
     /   \
    2     3
     \
      4
Output: 1 2 4

🛠️ Approach:
- Perform level order traversal using a queue.
- Use a marker (NULL) to separate levels.
- At the beginning of each level, record the first node seen (leftmost).

🧮 Time Complexity: O(n), where n is the number of nodes.
🧮 Space Complexity: O(n), for the queue used in level order traversal.
*/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        queue<Node*> q1;
        q1.push(root);
        q1.push(NULL);
        ans.push_back(root->data);
        
        while (!q1.empty()) {
            Node* ptr = q1.front();
            q1.pop();
            
            if (ptr == NULL) {
                if (q1.empty()) break;
                ptr = q1.front();
                q1.pop();
                if (ptr == NULL) break;
                ans.push_back(ptr->data);
                q1.push(NULL);
            }
            
            if (ptr->left) q1.push(ptr->left);
            if (ptr->right) q1.push(ptr->right);
        }
        
        return ans;
    }
};
