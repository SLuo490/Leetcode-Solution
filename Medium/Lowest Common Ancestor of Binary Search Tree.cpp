#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
        int parentVal = root->val; 
        int pVal = p->val; 
        int qVal = q->val; 
        
        // if p and q's value is less than the root value, traverse to the right tree, else left tree
        if (pVal > parentVal && qVal > parentVal) {
            return lowestCommonAncestor(root->right, p, q); 
        } else if (pVal < parentVal && qVal < parentVal) {
            return lowestCommonAncestor(root->left, p, q); 
        } else {
            return root;
        }
    }
};

int main()
{
  return 0;
}