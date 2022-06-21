/************************************************************

    Following is the Binary Tree node structure:
    
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
void left(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL ))
        return;
    ans.push_back(root->data);
    if(root->left)    {
        left(root->left,ans);
        return;
    }
    if(root->right)    left(root->right,ans);
}
void bottom(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL)    return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    bottom(root->left,ans);
    bottom(root->right,ans);
}

void right(TreeNode<int>* root,stack<int>&st){
    if(root==NULL)    return;
    if(root->left==NULL && root->right==NULL)    return;
    st.push(root->data);
    if(root->right)    {
        right(root->right,st);
        return;
    }
    right(root->left,st);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    if(root==NULL)    return {};
    if(root->left==NULL && root->right==NULL)    return {root->data};
    vector<int> ans;
    ans.push_back(root->data);
    left(root->left,ans);
    bottom(root,ans);
    stack<int> st;
    right(root->right,st);
    while(st.empty()==false){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}