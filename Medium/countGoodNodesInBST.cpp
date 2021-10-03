/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
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
    
    //Preorder
    
    // P L R
    int countGoodNodes (TreeNode* root, int maxVal) {
        if (root == nullptr) return 0;
        
        int goodNodes = 0;
        
        //if the currnode is greater than or equal to max val, then we have a good node
        if (root->val >= maxVal) {
            //update max val
            maxVal = root->val;
            goodNodes++;
        }
        
        //recursive call left and right
        return goodNodes + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countGoodNodes(root, root->val);
    }
};
