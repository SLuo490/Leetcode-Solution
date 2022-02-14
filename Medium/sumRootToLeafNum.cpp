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
    int sumNumbers(TreeNode* root) {
        return rootToLeafPathSum(root, 0); 
    }
    
    int rootToLeafPathSum(TreeNode* currNode, int pathSum) {
        if (!currNode) return 0; 
        
        // convert the pathSum to a integer
        // 1->2->3
            // 1 = 10 * 0 + 1 = 1
            // 2 = 10 * 1 + 2 = 12
            // 3 = 12 * 10 + 3 = 123
        pathSum = 10 * pathSum + currNode->val; 
        
        // if the currNode is a leaf, return the pathSum
        if (currNode->left == nullptr && currNode->right == nullptr) {
            return pathSum; 
        }
        
        // recursive call the left and right tree and add the pathSum
        return rootToLeafPathSum(currNode->left, pathSum) + rootToLeafPathSum(currNode->right, pathSum); 
    }
};
