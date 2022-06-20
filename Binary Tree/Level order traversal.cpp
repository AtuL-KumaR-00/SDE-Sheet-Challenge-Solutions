#include<bits/stdc++.h>

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root==NULL)    return {};
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        int n=q.size();
        for(int i=0;i<n;i++){
            BinaryTreeNode<int>* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
            if(curr->left)    q.push(curr->left);
            if(curr->right)    q.push(curr->right);
        }
    }
    return ans;
}