#include<bits/stdc++.h>
int LCS(string s, string t, int n,int m,vector<vector<int>> &dp){
    if(n==0||m==0)    return 0;
    if(s[n-1]==t[m-1])    return dp[n][m] = (LCS(s,t,n-1,m-1,dp)+1);
    else {
        //return max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
        
        if(dp[n-1][m]==-1){
            dp[n-1][m]=LCS(s,t,n-1,m,dp); 
        }
        if(dp[n][m-1]==-1){
            dp[n][m-1]=LCS(s,t,n,m-1,dp);
        }
        return max(dp[n-1][m],dp[n][m-1]);
    }
}

int lcs(string s, string t)
{
	int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(1001,vector<int>(1001,-1));
    return LCS(s,t,n,m,dp);
}