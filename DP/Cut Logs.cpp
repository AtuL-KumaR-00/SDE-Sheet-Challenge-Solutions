#include<bits/stdc++.h>
int cut(int k, int n,vector<vector<int>>&dp)
{
    if(k==1)    return n;
    if(n==0|| n==1)    return n;
    
    if(dp[k][n]!=-1)    return dp[k][n];
    int mn=INT_MAX;
    for(int i=1;i<=n;i++){
        int low,high;
        if(dp[k-1][i-1]!=-1)    low=dp[k-1][i-1];
        else{
            low=cut(k-1,i-1,dp);
            dp[k-1][i-1]=low;
        }    
        if(dp[k][n-i]!=-1)    high=dp[k][n-i];
        else {
            high=cut(k,n-i,dp);
            dp[k][n-i]=high;
        }
        int temp=1+max(low,high);
        mn=min(mn,temp);
    }
    return dp[k][n]=mn;
}

int cutLogs(int n, int k)
{
    int dp[k + 1][n + 1];
        for(int i = 1; i <= n; i++){
            dp[1][i] = 1; 
            dp[0][i] = 0;
        }
        for(int i = 1; i<= k; i++){
            dp[i][1] = i;
        }
        for(int i = 2; i <= k; i++){
            for(int j = 2; j <= n; j++){
                dp[i][j] = i;
                for(int m = 1; m <= i; m++){
                    dp[i][j] = min(max(dp[m - 1][j - 1], dp[i - m][j])+1, dp[i][j]);
                }
            }
        }
        return dp[k][n];
}
