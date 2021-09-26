/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //edge cases 
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        
        //traverse both tree using 2 queue
        queue<TreeNode*> queue1;
        queue<TreeNode*> queue2;
        queue1.push(p);
        queue2.push(q);
        
        //traverse both queue
        while (!queue1.empty() && !queue2.empty()) {
            int levelSize = queue1.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = queue1.front();
                queue1.pop();
                
                TreeNode* currNode2 = queue2.front();
                queue2.pop();
                
                //check if the current level of queue1 and queue2 is not equal
                if (currNode->val != currNode2->val) {
                    return false;            
                }
                
                //add child node of queue1 and 2
                if (currNode->left == nullptr && currNode2->left != nullptr) {
                    return false;
                }
                if (currNode->right == nullptr && currNode2->right != nullptr) {
                    return false;
                }
                
                //add the children node of currNode in queue 1
                if (currNode->left != nullptr) queue1.push(currNode->left);
                if (currNode->right != nullptr) queue1.push(currNode->right);
                
                //add the children node of currNode2 in queue 2
                if (currNode2->left != nullptr) queue2.push(currNode2->left);
                if (currNode2->right != nullptr) queue2.push(currNode2->right);
            }
        }
        //if queue1 is empty and queue2 is not empty, then it is not equal
        //same for the other direction
        if (!queue1.empty() && queue2.empty()) {
                return false;
        }
        if (queue1.empty() && !queue2.empty()) {
                return false;
        }
        return true;
    }
};

//Recursion
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }

