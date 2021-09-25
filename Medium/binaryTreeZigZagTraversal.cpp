/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //if there is 
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        bool leftToRight = true;
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> currLevel (levelSize);
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //zig zag add
                if (leftToRight) {
                    currLevel[i] = currNode->val;
                } else {
                    currLevel[levelSize - 1 - i] = currNode->val;
                }
                
                //add children of currNode
                if (currNode -> left != nullptr) queue.push(currNode->left);
                if (currNode-> right != nullptr) queue.push(currNode->right);
            }
            leftToRight = !leftToRight;
            result.push_back(currLevel);
        }
        return result;
    }
};
