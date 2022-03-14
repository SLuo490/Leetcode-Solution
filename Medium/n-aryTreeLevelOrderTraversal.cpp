/*
Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; 
        if (!root) return res; 
        
        queue<Node*> q; 
        q.push(root); 
        
        while (!q.empty()) {
            vector<int> currLevel; 
            int levelSize = q.size(); 
            
            for (int i = 0; i < levelSize; i++) {
                Node* currNode = q.front(); 
                q.pop(); 
                
                currLevel.push_back(currNode->val);
                
                // Add the children of node to queue
                for (Node* node : currNode->children) {
                    q.push(node); 
                }
            }
            res.push_back(currLevel); 
        }
        
        return res; 
    }
};
