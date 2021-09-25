/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
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
    int minDepth(TreeNode* root) {
        int minDepth = 0;
        if (root == nullptr) return 0; //edge case, no root
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            minDepth++;
            int levelSize = queue.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //we reached the leaf node, return the minDepth
                if (currNode->left == nullptr && currNode->right == nullptr) {
                    return minDepth;
                }
                
                //we did not reach the leaf node, add the children for next level
                if (currNode->left != nullptr) queue.push(currNode->left);
                if (currNode->right != nullptr) queue.push(currNode->right);
            }
        }
        return minDepth;
    }
};
