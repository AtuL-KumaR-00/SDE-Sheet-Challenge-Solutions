/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class ob{
    public:
        TreeNode<int> *prev=NULL;
        void flatten(TreeNode<int> *root){
            if(root==NULL)    return;
            flatten(root->right);
            flatten(root->left);
            root->right=prev;
            root->left=NULL;
            prev=root;
        }
};
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    ob obj;
    obj.flatten(root);   
    return root;
}