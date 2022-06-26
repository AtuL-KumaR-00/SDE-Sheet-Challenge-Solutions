#include<bits/stdc++.h>

bool DFS(vector<vector<int>> &graph,vector<bool> &vis,int node, int parent){
    vis[node]=true;
    for(int i:graph[node]){
        if(!vis[i]){
            if(DFS(graph,vis,i,node))
                return true;
        }  
        else if(vis[i]==true && i!=parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1);
    vector<bool> vis(n+1,false);
    for(int i=0;i<m;i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(DFS(graph,vis,i,-1)){
                return "Yes";
            }
        }
    }
    return "No";
}
