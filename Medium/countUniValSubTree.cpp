/*
Given the root of a binary tree, return the number of uni-value subtrees.
A uni-value subtree means all nodes of the subtree have the same value.

Example 1:
Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [5,5,5,5,5,null,5]
Output: 6
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
private:
    int count = 0;    
public:
    bool isUniVal (TreeNode* root) {
        //if it is a leaf then it is a uni val
        if (root->left == nullptr && root->right == nullptr) {
            count++;
            return true;
        }
        
        bool uni_val = true;
        
        //if it is not a leaf, but a children of root and has the same value as the root, then it is a unival
        if (root->left != nullptr) {
            uni_val = isUniVal(root->left) && uni_val && root->left->val == root->val;
        }
        
        if (root->right != nullptr) {
            uni_val = isUniVal(root->right) && uni_val && root->right->val == root->val;
        }
        
        if (!uni_val) return false;
        count++;
        return true;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) return 0;
        isUniVal(root);
        return count;
    }
};
