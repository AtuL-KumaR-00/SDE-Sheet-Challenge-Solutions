#include<bits/stdc++.h>
int f(vector<int> &arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j)    return 0;
    
    if(dp[i][j]!=-1)    return dp[i][j];
    int minm=INT_MAX;
    int temp;
    for(int k=i;k<=j-1;k++){
        temp=f(arr,i,k,dp)+f(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        minm=min(minm,temp);
    }
    return dp[i][j]= minm;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    return f(arr,1,N-1,dp);
}