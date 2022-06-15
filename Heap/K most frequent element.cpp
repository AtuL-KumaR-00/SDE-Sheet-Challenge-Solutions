#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        pq.push({it->second,it->first});
        if(pq.size()>k)    pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}