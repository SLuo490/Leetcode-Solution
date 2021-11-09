/*
Given the root of a binary tree, return the sum of all left leaves.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0
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
    //BFS
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0; 
        queue<pair<TreeNode*, bool>> q; 
        q.push({root, false}); 
        
        while (!q.empty()) {
            auto [curr, isLeft] = q.front(); 
            q.pop(); 
            
            if (!curr->left && !curr->right && isLeft) {
                ans += curr->val; 
            }
            
            if (curr->left != nullptr) q.push({curr->left, true}); 
            if (curr->right != nullptr) q.push({curr->right, false}); 
        }
        return ans; 
    }
    
    //DFS
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false); 
    }
    int dfs(TreeNode* root, bool isLeaf) {
        if (!root) return 0; 
        
        if (!root->left && !root->right) {
            if (isLeaf) {
                return root->val;
            } else {
                return 0; 
            }    
        }
        
        return dfs(root->left, true) + dfs(root->right, false); 
    }
};
