#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    int siz=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
            siz++;
        }
        else{
            int inx=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[inx]=arr[i];
        }
    }
    return siz;
}

Approach 2:

#include<bits/stdc++.h>
//int count=0;
int f(int idx,int prevIdx,int arr[], int n,vector<vector<int>>&dp){
    if(idx==n)    return 0;
    int len=0;
    if(dp[idx+2][prevIdx+1]!=-1)    len=dp[idx+2][prevIdx+1];
    else {
        dp[idx+2][prevIdx+1] = 0+f(idx+1,prevIdx,arr,n,dp);
        len=dp[idx+2][prevIdx+1];
    }
    if(prevIdx==-1 || arr[idx]>arr[prevIdx]){
        if(dp[idx+2][idx+1] ==-1)
            dp[idx+2][idx+1] = 1+f(idx+1,idx,arr,n,dp);
        len=max(len, dp[idx+2][idx+1]);
    }
    return dp[idx+1][prevIdx+1]=len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
    return f(0,-1,arr,n,dp);
}