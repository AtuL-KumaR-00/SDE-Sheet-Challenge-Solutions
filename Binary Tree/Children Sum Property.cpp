/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void increment(BinaryTreeNode < int > *node, int diff)
{
    /* IF left child is not
    NULL then increment it */
    if(node->left != NULL)
    {
        node->left->data = node->left->data + diff;
     
        // Recursively call to fix
        // the descendants of node->left
        increment(node->left, diff);
    }
    else if (node->right != NULL) // Else increment right child
    {
        node->right->data = node->right->data + diff;
     
        // Recursively call to fix
        // the descendants of node->right
        increment(node->right, diff);
    }
}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL)    return;
    if(root->left==NULL && root->right==NULL)    return;
    changeTree(root->left);
    changeTree(root->right);
    
    int sum=0;
    if(root->left)    sum+=root->left->data;
    if(root->right)    sum+=root->right->data;
    if(sum>root->data)    root->data = sum;
    else if(sum<root->data){
        increment(root, root->data - sum);
    }
    // printPreorder(root);
}  
