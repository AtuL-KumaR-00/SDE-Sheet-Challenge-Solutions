#include<bits/stdc++.h>
int f(vector<int> &price,int n, int i,vector<vector<int>>&dp){
    if(n==0)    return 0;
    if(n<0)    return -1e9;
    if(i==0)    return n*price[0];
    
    if(dp[i][n]!=-1)    return dp[i][n];
    
    return dp[i][n]=max(f(price,n,i-1,dp),price[i]+ f(price,n-(i+1),i,dp));
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+5,vector<int>(n+5,-1));
    return f(price,n,n-1,dp);
}
