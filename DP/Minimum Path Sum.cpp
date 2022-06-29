#include<bits/stdc++.h>

int f(vector<vector<int>> &grid,int i,int j,vector<vector<int>>&dp){
    if(i==-1 || j==-1)    return 1e9;
    if(i==0 && j==0)    return grid[0][0];
    
    if(dp[i][j]!=-1)    return dp[i][j];
    return dp[i][j] = min(f(grid,i-1,j,dp)+grid[i][j], f(grid,i,j-1,dp)+grid[i][j]);
}


int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return f(grid,grid.size()-1,grid[0].size()-1,dp);
}