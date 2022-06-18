#include<bits/stdc++.h>
string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.size();
    int start=0,end=0;
    int maxm=1;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    
    for(int i=0;i<n;i++){
        dp[i][i]=true;
        if(i<n-1 && str[i]==str[i+1])    {
            dp[i][i+1]=true;
            if(2 > maxm){
                    start=i;
                    end=i+1;
                    maxm=2;
            }
        }
    }
    
    for(int k=3;k<=n;k++){
        for(int i=0;i<n;i++){
            int j=i+k-1;
            if(j>=n)    continue;
            if(str[i]==str[j] && dp[i+1][j-1]){
                dp[i][j]=true;
                if(j-i+1 > maxm){
                    start=i;
                    end=j;
                    maxm=j-i+1;
                }
            }
        }
    }
    
    string s="";
    for(int i=start;i<=end;i++)    s+=str[i];
    return s;
}