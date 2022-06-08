#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> mp;
    int res=0,sum=0;
    mp[0]=-1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(mp.find(sum)!=mp.end()){
            //if(sum==0)    res=max(res,i-mp[sum]);
            res=max(res,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    return res;
}