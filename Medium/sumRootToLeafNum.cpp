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
    int DFS (TreeNode* currNode, int totalSum) {
        if (currNode == nullptr) return 0;
        
        //convert path to int (1->2 = 12)
        //10 * 0 + 1 = 1
        //10 * 1 + 2 = 12
        totalSum = 10 * totalSum + currNode->val;
        
        if (currNode->left == nullptr && currNode->right == nullptr) {
            return totalSum;
        }
        
        return DFS (currNode->left, totalSum) + DFS (currNode->right, totalSum);
    }
    int sumNumbers(TreeNode* root) {
        return DFS (root, 0);
    }
};
