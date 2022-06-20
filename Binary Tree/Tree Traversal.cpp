#include<bits/stdc++.h>
void fin(BinaryTreeNode<int> * root, vector<int>&ans){
    if(root==NULL)    return;
    fin(root->left,ans);
    ans.push_back(root->data);
    fin(root->right,ans);
}
void fpre(BinaryTreeNode<int>* root, vector<int>&ans){
    if(root==NULL)    return;
    ans.push_back(root->data);
    fpre(root->left,ans);
    fpre(root->right,ans);
}
void fpost(BinaryTreeNode<int>* root, vector<int>&ans){
    if(root==NULL)    return;
    fpost(root->left,ans);
    fpost(root->right,ans);
    ans.push_back(root->data);  
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    fin(root,ans[0]);
    fpre(root,ans[1]);
    fpost(root,ans[2]);
    return ans;
}