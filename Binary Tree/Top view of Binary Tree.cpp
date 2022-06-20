#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)    return {};
    map<int,TreeNode<int>*> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    vector<int> ans;
    mp[0]=root;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode<int>* curr=q.front().first;
            int vdist=q.front().second;
            if(mp.find(vdist)==mp.end())
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
        ans.push_back(it->second->val);    
    }
    return ans;
}