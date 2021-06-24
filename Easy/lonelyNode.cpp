/*
In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.
Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.

 
Example 1:
Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.

Example 2:
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.
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
    void dfs(vector<int> &nums, TreeNode *root) {
        if (!root) {
            return;
        }
        //check left and not right
        if (root->left && !root->right) {
            //add the value to nums
            nums.push_back(root->left->val);
        }
        if (root->right && !root->left) {
            //add the values to nums;
            nums.push_back(root->right->val);
        }
        //recursion
        dfs(nums, root->left);
        dfs(nums, root->right);
        
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int>res;
        dfs(res,root);
        return res;
    }
};
