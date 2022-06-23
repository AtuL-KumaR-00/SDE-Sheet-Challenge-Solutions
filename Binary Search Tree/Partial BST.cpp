/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)    return true;
    int left=INT_MIN;
    int right=INT_MAX;
    if(root->left)    left=root->left->data;
    if(root->right)    right=root->right->data;
    if(root->data<=right && root->data>=left){
        return validateBST(root->left) && validateBST(root->right);
    }
    else return false;   
}