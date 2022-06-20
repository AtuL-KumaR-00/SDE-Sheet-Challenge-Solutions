#include<bits/stdc++.h>
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root==NULL)    return {};
    queue<TreeNode<int>*> q;
    vector<int> ans;
    q.push(root);
    while(q.empty()==false){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode<int>* curr=q.front();
            q.pop();
            if(curr->left)    q.push(curr->left);
            if(curr->right)    q.push(curr->right);
            if(i==0){
                ans.push_back(curr->data);
            }
        }
    }
    return ans;
}