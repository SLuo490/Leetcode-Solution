class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //if root is empty return root
        if (!root)
        {
            return root;
        }
        
        //create a treenode
        TreeNode *node = new TreeNode();
        
        //recursive search 
        if (val < root->val)
        {
            //recursice search the left BST if the val is less than the root's val
            node = searchBST(root->left, val);
        }
        else if (val > root->val)
        {
            //recursice search the right BST if the val is greater than the root's val
            node = searchBST(root->right, val);   
        }
        else 
        {
            //the val is the root, set node to root
            node = root;    
        }
        return node;
    }
};
