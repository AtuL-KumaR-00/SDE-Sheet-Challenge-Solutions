#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(root==NULL)    return {};
    map<int,vector<TreeNode<int>*>> mp;
    queue<pair<TreeNode<int>*,int>> q;
    //mp[0].push_back(root);
    q.push({root,0});
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode<int>* curr=q.front().first;
            int vdist=q.front().second;
            q.pop();
            mp[vdist].push_back(curr);
            if(curr->left)    q.push({curr->left,vdist-1});
            if(curr->right)    q.push({curr->right,vdist+1});
        }
    }
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<TreeNode<int>*> temp=it->second;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]->data);
        }
    }
    return ans;
}