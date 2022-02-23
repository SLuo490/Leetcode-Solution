/*
Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 
We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

 
Example 1:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0
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
    bool isValidPath(TreeNode* currNode, vector<int>& arr, int arrIdx) {
        if (!currNode) return false; 
        
        // if the arrIdx is greater than the arr size or current index is not equal to arr element
        if (arrIdx >= arr.size() || currNode->val != arr[arrIdx]) return false; 
        
        // if arrIdx is eqal to arr size - 1 and is leaf, return true
        if (arrIdx == arr.size() - 1 && currNode->left == nullptr && currNode->right == nullptr) {
            return true; 
        }
        
        // recursive call the left and right tree
        return isValidPath(currNode->left, arr, arrIdx + 1) || isValidPath(currNode->right, arr, arrIdx + 1); 
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) return arr.empty(); 
        
        return isValidPath(root, arr, 0); 
    }
};
