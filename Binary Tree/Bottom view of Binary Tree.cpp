#include<bits/stdc++.h>
vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,BinaryTreeNode<int>*> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    vector<int> ans;
    mp[0]=root;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* curr=q.front().first;
            int vdist=q.front().second;
            mp[vdist]=curr;
            q.pop();
            if(curr->left)    {
                q.push({curr->left,vdist-1});
            }
            if(curr->right)    {
                q.push({curr->right,vdist+1});
            }
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second->data);    
    }
    return ans;
}