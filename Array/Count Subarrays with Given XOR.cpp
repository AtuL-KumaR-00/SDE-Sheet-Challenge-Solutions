#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    for(int i=1;i<arr.size();i++){
        arr[i]=arr[i-1] ^ arr[i];
    }
    unordered_map<int,int> mp;
    int res=0;
    for(int i=0;i<arr.size();i++){
        int temp=arr[i] ^ x;
        if(mp.find(temp)!=mp.end())    res+=mp[temp];
        if(arr[i]==x) res++;
        mp[arr[i]]++;
    }
    return res;
}