#include<bits/stdc++.h>
void f(vector<int>&v,int pos,vector<int> contri,vector<vector<int>>&ans){
    if(pos==v.size()){
        ans.push_back(contri);
        return;
    }
    f(v,pos+1,contri,ans);
    contri.push_back(v[pos]);
    f(v,pos+1,contri,ans);
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> contri;
    f(v,0,contri,ans);
    return ans;
}