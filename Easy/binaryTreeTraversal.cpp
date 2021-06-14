//Inorder Traversal (Left Parent Right)
void inorder(vector<int> & value, TreeNode* node)
{
    //base case
    if (node == nullptr) return;
    if (node->left)
    {
        preorder(value, node->left);
    }
    value.push_back(node->val);
    if (node->right)
    {
        preorder(value, node->right);
    }
}
vector<int> inorderTreeTraversak(TreeNode* root) {
    vector<int> value;
    if (root == nullptr) return value;
    inorder(value, root);
    return value;
}

//Preorder Traversal (Parent, Left, Right)
void preorder(vector<int> & value, TreeNode* node)
{
    //base case
    if (node == nullptr) return;
    value.push_back(node->val);
    if (node->left)
    {
        preorder(value, node->left);
    }
    if (node->right)
    {
        preorder(value, node->right);
    }
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> value;
    if (root == nullptr) return value;
    preorder(value, root);
    return value;
}

//Postorder Traversal (Left, Right, Parent)
void postorder(vector<int> & value, TreeNode* node)
{
    //base case
    if (node == nullptr) return;
    if (node->left)
    {
        preorder(value, node->left);
    }
    if (node->right)
    {
        preorder(value, node->right);
    }
    value.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> value;
    if (root == nullptr) return value;
    preorder(value, root);
    return value;
}






















