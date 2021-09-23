/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        //empty root, return an empty result
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> queue;
        //push root to queue
        queue.push(root);
        
        while (!queue.empty()) {
            //the size of queue (number of node in current level)
            int levelSize = queue.size();
            vector<int> currLevel;
            //loop through the queue size 
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //add node to current level
                currLevel.push_back(currNode->val);
                
                //insert children of current node to queue
                if (currNode -> left != nullptr) {
                    queue.push(currNode->left);
                }
                
                if (currNode -> right != nullptr) {
                    queue.push(currNode->right);
                }
            }
            result.push_back(currLevel);
        }
        return result;
    }
};
