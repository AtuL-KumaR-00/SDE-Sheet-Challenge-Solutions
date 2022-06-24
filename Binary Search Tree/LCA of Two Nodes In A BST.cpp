/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>

bool find(TreeNode<int>* root, TreeNode<int>* x){
    if(root==NULL)    return false;
    if(root == x)    return true;
    
    if(root->data > x->data)    return find(root->left,x);
    if(root->data < x->data)    return find(root->right,x);
    //return false;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root==NULL)    return NULL;
        if(root->data == P->data || root->data == Q->data)    return root;
        
        bool leftp = find(root->left,P);
        bool leftq = find(root->left,Q);
        if(leftp==false && leftq==false)
            return LCAinaBST(root->right,P,Q);
        if((leftp==false && leftq==true) || (leftp==true && leftq==false)){
            return root;
        }
        return LCAinaBST(root->left,P,Q);
}
