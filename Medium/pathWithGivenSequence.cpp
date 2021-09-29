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

https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/

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
    bool DFS (TreeNode *currNode, vector<int>& arr, int sequenceIdx) {
        if (currNode == nullptr) return false;
        
        //check if the current idx of arr matches the currnode val
        if (sequenceIdx >= arr.size() || currNode->val != arr[sequenceIdx]) {
            return false;
        }
        
        //if we reach a leaf and the sequence idx is equal to the length of arr then we have a match
        if (currNode->left == nullptr && currNode->right == nullptr && sequenceIdx == arr.size() - 1) {
            return true;
        }
        
        //traverse the left and right subtree
        return DFS(currNode->left, arr, sequenceIdx + 1) || DFS(currNode->right, arr, sequenceIdx + 1);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return DFS(root, arr, 0);
    }
};
