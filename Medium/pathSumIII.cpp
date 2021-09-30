/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
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
    int countSum (TreeNode* currNode, int sum, vector<int>& currPath) {
        if (currNode == nullptr) return 0;
        
        currPath.push_back(currNode->val);
        
        int pathCount = 0, pathSum = 0;
        
        //iterate the currPath backwards and count see if there is a path that adds up to sum
        for (vector<int>::reverse_iterator itr = currPath.rbegin(); itr != currPath.rend(); ++itr) {
            pathSum += *itr;
            if (pathSum == sum) {
                pathCount++;
            }
        }
        
        //traverse left and right subtree 
        pathCount += countSum (currNode->left, sum, currPath);
        pathCount += countSum (currNode->right, sum, currPath);
        
        //remove the last element in currPath to backtrack
        currPath.pop_back();
        
        return pathCount; //this will keep track of the pathCount when we reach end of a path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currPath;
        return countSum (root, targetSum, currPath);
    }
};
