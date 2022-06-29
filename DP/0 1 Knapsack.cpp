#include<bits/stdc++.h>
int f(int idx, vector<int> &values, vector<int> &weights, int n, int w,int &profit){
    if(w<0 || idx>=n)    return profit;
    
    int nottake = f(idx+1,values,weights,n,w,profit);
    
    int take=0;
    if(weights[idx]<=w){
        w=w-weights[idx];
        profit += values[idx];
        take = f(idx+1,values,weights,n,w,profit);
        profit-=values[idx];
    }
    return max(nottake,take);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	int profit=0;
    return f(0,values,weights,n,w,profit);
    //return profit;
}


APPROACH 2:

#include<bits/stdc++.h>
int f(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>>&dp){
    if(n==0 || w==0)    return 0;
    if(dp[n][w]!=-1)    return dp[n][w];
    if(weights[n-1]<=w){
        return dp[n][w]=max(values[n-1] + f(values,weights,n-1,w-weights[n-1],dp), f(values,weights,n-1,w,dp));
    }else{
        return dp[n][w]=f(values,weights,n-1,w,dp);
    }
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return f(values,weights,n,w,dp);
}

