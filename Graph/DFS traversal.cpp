#include<bits/stdc++.h>
void DFS(vector<vector<int>> &graph, vector<int> &contri, vector<bool>&visited, int node){
    if(visited[node])    return;
    
    visited[node]=true;
    contri.push_back(node);
    for(int i=0;i<graph[node].size();i++){
       DFS(graph,contri,visited,graph[node][i]); 
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V);
    vector<vector<int>> ans;
    vector<bool> visited(V,false);
    
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> contri;
            DFS(graph,contri,visited,i);
            ans.push_back(contri);
        }
    }
    return ans;
}