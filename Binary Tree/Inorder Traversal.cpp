#include<bits/stdc++.h>
void f(TreeNode* root, vector<int>&ans){
    if(root==NULL)    return;
    f(root->left,ans);
    ans.push_back(root->data);
    f(root->right,ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    f(root,ans);
    return ans; 
}