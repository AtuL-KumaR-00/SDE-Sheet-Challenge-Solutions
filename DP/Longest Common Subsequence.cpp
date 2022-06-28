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


APPROACH 2:
 
#include<bits/stdc++.h>


int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int temp=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[0])    temp=1;
        dp[i][0]=temp;
    }
    temp=0;
    for(int j=0;j<m;j++){
        if(s[0]==t[j])    temp=1;
        dp[0][j]=temp;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s[i]==t[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n-1][m-1];
}