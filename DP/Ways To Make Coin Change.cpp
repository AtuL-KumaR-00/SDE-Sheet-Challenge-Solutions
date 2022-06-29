#include<bits/stdc++.h>

long f(int *&denominations, int value,int idx,vector<vector<long>> &dp){
    if(value==0)    return 1;
    if(value<0)    return 0;
    if(idx==-1)    return 0;
    
    if(dp[idx][value]!=-1)    return dp[idx][value];
    long nottake= 0+f(denominations,value,idx-1,dp);
    long take = f(denominations,value-denominations[idx],idx,dp);
    return dp[idx][value]=take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n+1,vector<long>(value+1,-1));
    return f(denominations,value,n-1,dp);
}