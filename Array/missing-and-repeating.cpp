#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[i]=0;
    }
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int x,y;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==0)    x=it->first;
        if(it->second==2)    y=it->first;
    }
    return {x,y};
}