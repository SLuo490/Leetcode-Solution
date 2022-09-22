#include <bits/stdc++.h>
using namespace std;

/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree.
Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

Example 1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:
Input: tree = [7], target =  7
Output: 7
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // DFS 
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      if (original == nullptr) return nullptr; 
      
      if (original == target) return cloned; 
      
      TreeNode* left = getTargetCopy(original->left, cloned->left, target); 
      TreeNode* right = getTargetCopy(original->right, cloned->right, target); 
      
      return (left != nullptr) ? left : right; 
  }

  // BFS 
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original) return nullptr; 
    
    queue<TreeNode*> q; 
    q.push(cloned); 
    
    while (!q.empty()) {
        int level = q.size(); 
        for (int i = 0; i < level; i++) {
            TreeNode* currNode = q.front(); 
            q.pop(); 
            
            if (currNode->val == target->val) {
                return currNode; 
            }
            
            if (currNode->left) q.push(currNode->left); 
            if (currNode->right) q.push(currNode->right); 
        }
    }
    return nullptr; 
  }
};

int main()
{
  return 0;
}