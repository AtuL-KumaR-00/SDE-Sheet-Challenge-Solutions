#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    int freq=arr.size()/3;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>freq) ans.push_back(it->first);
    }
    return ans;
}