#include<bits/stdc++.h>
bool f(vector<int>&arr, int k,int idx,vector<vector<int>>&dp){
    if(k==0)    return true;
    if(k<0 || idx<0)    return false;
    
    if(dp[idx][k]!=-1)    return dp[idx][k];
    bool nottake=f(arr,k,idx-1,dp);
    
    bool take=f(arr,k-arr[idx],idx-1,dp);
    return dp[idx][k]= take|nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(arr,k,n-1,dp);
}