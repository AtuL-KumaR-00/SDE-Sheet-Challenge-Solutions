#include<bits/stdc++.h>
void dfs(int i,int j, int** arr, int n,int m, vector<vector<bool>>&vis){
    if(i<0 || i>=n || j<0 || j>=n || arr[i][j]==0 || vis[i][j]==true)    return;
    vis[i][j]=true;
    dfs(i+1,j,arr,n,m,vis);
    dfs(i,j+1,arr,n,m,vis);
    dfs(i-1,j,arr,n,m,vis);
    dfs(i,j-1,arr,n,m,vis);
    dfs(i+1,j+1,arr,n,m,vis);
    dfs(i+1,j-1,arr,n,m,vis);
    dfs(i-1,j+1,arr,n,m,vis);
    dfs(i-1,j-1,arr,n,m,vis);
}
int getTotalIslands(int** arr, int n, int m)
{
    int cnt=0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && vis[i][j]==false){
                dfs(i,j,arr,n,m,vis);
                cnt++;
            }
        }
    }
    return cnt;
}
