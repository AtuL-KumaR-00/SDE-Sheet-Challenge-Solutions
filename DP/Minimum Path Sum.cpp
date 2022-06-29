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


APPROACH 2:

#include<bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)    dp[i][j]=grid[i][j];
            else  {
                int down=grid[i][j];
                if(i>0)
                    down+=dp[i-1][j];
                else down+=1e9;
                
                int right=grid[i][j];
                if(j>0)
                    right+=dp[i][j-1];
                else right+=1e9;
                
                dp[i][j]=min(down,right);
            }
        }
    }
    return dp[n-1][m-1];
}