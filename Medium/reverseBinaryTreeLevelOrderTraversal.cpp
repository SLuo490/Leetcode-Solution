/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> currLevel;
            
            //traverse level of queue
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //add current node to current level
                currLevel.push_back(currNode->val);
                
                //add children of current node to queue to prep for next level
                if (currNode->left != nullptr) {
                    queue.push(currNode->left);
                }
                if (currNode -> right != nullptr) {
                    queue.push(currNode->right);
                }
            }
            //push back the current level to result
            result.push_back(currLevel);
        }
        //return in reverse order
        return vector(result.rbegin(), result.rend());
    }
};
