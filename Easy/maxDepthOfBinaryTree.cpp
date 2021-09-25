/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Example 3:
Input: root = []
Output: 0

Example 4:
Input: root = [0]
Output: 1
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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if (root == nullptr) return 0; //edge case, no root
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            maxDepth++;
            int levelSize = queue.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //we did not reach the leaf node, add the children for next level
                if (currNode->left != nullptr) queue.push(currNode->left);
                if (currNode->right != nullptr) queue.push(currNode->right);
            }
        }
        return maxDepth;
    }
};
