/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []
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
    void recursivePath (TreeNode* currNode, int targetSum, vector<int>& currPath, vector<vector<int>>& allPaths) {
        if (currNode == nullptr) return;
        
        //push the currentNode to currPath
        currPath.push_back(currNode->val);
        
        //if the currNode->val is equal to sum and is leaf, we found a path, so add it to the allPaths
        if (currNode->val == targetSum && currNode->left == nullptr && currNode->right == nullptr) {
            //add it to all paths
            allPaths.push_back(vector<int>(currPath));
        } else {
            //we need to do recursive call to left and right subtree
            recursivePath(currNode->left, targetSum - currNode->val, currPath, allPaths);
            recursivePath(currNode->right, targetSum - currNode->val, currPath, allPaths);
        }
        
        //pop_back the currNode from currPath because we did not find a path
        currPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currPath;
        
        //recursive call to find all paths
        recursivePath (root, targetSum, currPath, allPaths);
        
        return allPaths;
    }
    

};
