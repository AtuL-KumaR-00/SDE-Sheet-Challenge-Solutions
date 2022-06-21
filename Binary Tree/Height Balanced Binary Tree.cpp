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
#include<bits/stdc++.h>
int height(BinaryTreeNode<int>* root){
    if(root==NULL)    return 0;
    return 1+max(height(root->left),height(root->right));
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL)    return true;
    int left=height(root->left);
    int right=height(root->right);
    if(abs(left-right)<=1 && isBalancedBT(root->left) && isBalancedBT(root->right))
        return true;
    return false;
}