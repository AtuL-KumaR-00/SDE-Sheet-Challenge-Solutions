#include<bits/stdc++.h>

bool DFS(vector<vector<int>> &graph,vector<bool> &vis, vector<bool>&recSt,int node, int parent){
    vis[node]=true;
    recSt[node]=true;
    
    for(int i:graph[node]){
        if(!vis[i]){
            if(DFS(graph, vis, recSt, i, node))
                return true;
        }  
        else if(vis[i]==true && recSt[i]==true)
            return true;
    }
    recSt[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> graph(n+1);
    vector<bool> vis(n+1,false);
    vector<bool> recSt(n+1,false);
    for(int i=0;i<edges.size();i++){
        graph[edges[i].first].push_back(edges[i].second);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(DFS(graph, vis, recSt, i, -1)){
                return 1;
            }
        }
    }
    return 0;
}

APPROACH 2:

#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    int count=0;
    vector<int> indegree(n+1,0);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<edges.size();i++){
        indegree[edges[i].second]++;
        graph[edges[i].first].push_back(edges[i].second);
    }
    queue<int> q;
    for(int i=1;i<n;i++){
        if(indegree[i]==0)    q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        count++;
        q.pop();
        for(int child : graph[node]){
            indegree[child]--;
            if(indegree[child]==0)    
                q.push(child);
        }
    }
    if(count!=n)    return 1;
    return 0;
}