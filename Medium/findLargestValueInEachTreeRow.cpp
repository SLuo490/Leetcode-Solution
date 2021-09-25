/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]

Example 3:
Input: root = [1]
Output: [1]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            int maxNumInLevel = INT_MIN;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue.front();
                queue.pop();
                
                //find the maximum number in level
                maxNumInLevel = max (maxNumInLevel, currNode->val);
                
                //add the children of the currNode
                if (currNode->left != nullptr) queue.push(currNode->left);
                if (currNode->right != nullptr) queue.push(currNode->right);
            }
            res.push_back(maxNumInLevel);
            maxNumInLevel = INT_MIN;
        }
        return res;
    }
};
