/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
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
    void helper (TreeNode* root, vector<string>& res, string t) {
        //if root is not a leaf, then push back t
        if (!root->left && !root->right) { //Base case when we reach a leaf, we found a path
            res.push_back(t);
            return;
        }
        
        //recursive call left and right sub tree
        if (root->left) {
            //recurse left of the tree and add -> and next val
            helper(root->left, res, t + "->" + to_string(root->left->val));
        }
        if (root->right) {
            //recurse right of the tree and add -> and next val
            helper(root->right, res, t + "->" + to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) {
            return res;
        }
        
        helper(root, res, to_string(root->val));
        return res;
    }
};
