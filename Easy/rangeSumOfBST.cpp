/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
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
    void inOrder(TreeNode* root, vector<int>& value) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, value);
        value.push_back(root->val);
        inOrder(root->right, value);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> value;
        inOrder(root, value);
        
        int ans = 0;
        
        for (int i = 0; i < value.size(); i++) {
            if (value[i] >= low && value[i] <= high) {
                ans += value[i];
            }
        }
        return ans;
    }
};
