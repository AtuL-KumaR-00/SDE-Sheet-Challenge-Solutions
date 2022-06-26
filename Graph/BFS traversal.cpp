#include<bits/stdc++.h>

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    queue<int> q;
    vector<int> ans;
    vector<vector<int>> graph(vertex);
    vector<bool> visited(vertex,false);
    for(int i=0;i<edges.size();i++){
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    for(int i=0;i<vertex;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    q.push(0);
    visited[0]=true;
    while(q.empty()==false){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            if(!visited[graph[node][i]]){
                q.push(graph[node][i]);
                visited[graph[node][i]]=true;
            }
        }
    }
    for(int i=0;i<vertex;i++){
        if(!visited[i])    ans.push_back(i);
    }
    return ans;
}