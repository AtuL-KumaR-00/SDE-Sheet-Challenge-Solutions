#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> indegree(v,0);
    vector<vector<int>> graph(v);
    for(int i=0;i<edges.size();i++){
        indegree[edges[i][1]]++;
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)    q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(int child : graph[node]){
            indegree[child]--;
            if(indegree[child]==0)    
                q.push(child);
        }
    }
    return ans;
}