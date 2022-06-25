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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root== NULL)
        return root;
    BinaryTreeNode<int>* l=BTtoDLL(root->left);
    BinaryTreeNode<int>* r=BTtoDLL(root->right);
    BinaryTreeNode<int>* temp=l;
    while( l!=NULL && l->right!=NULL)
    l=l->right;
    if(l!=NULL)
    l->right=root;
    root->left=l;
    if(r!=NULL)
    r->left=root;
    root->right=r;
    return temp!=NULL?temp:root;
}