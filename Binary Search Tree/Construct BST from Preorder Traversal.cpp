/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* f(vector<int> &preOrder,int lo,int hi){
    if(lo>hi)    return NULL;
    int temp=preOrder[lo];
    int idx=lo+1;
    for(;idx<=hi;idx++){
        if(preOrder[idx]>temp)
            break;
    }
    
    TreeNode<int>* root=new TreeNode<int>(temp);
    root->left=f(preOrder,lo+1,idx-1);
    root->right=f(preOrder,idx,hi);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int n=preOrder.size();
    return f(preOrder,0,n-1);
}