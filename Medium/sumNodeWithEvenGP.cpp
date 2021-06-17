/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even-valued grandparent, return 0.

Example 1:
https://assets.leetcode.com/uploads/2019/07/24/1473_ex1.png
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
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
    void traverse(TreeNode* node, int grandparent, int parent, int &count)
    {
        if (node == nullptr) return;
        if (grandparent % 2 == 0)
        {
            count += node->val;
        }
        traverse(node->left, parent, node->val,count);
        traverse(node->right, parent, node->val,count);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return 0;
        traverse(root, -1, -1, count);
        return count;
    }
};
