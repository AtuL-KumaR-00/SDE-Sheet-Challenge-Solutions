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


APPROACH 2:

#include<bits/stdc++.h>
void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{     
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    vector<int> ans;
    bool visited[V]; 
    for(int i = 0;i<V; i++) 
        visited[i] = false;
    stack<int> st;
    vector<int> adj[V];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        ans.push_back(u);
        //cout<<u<<" ";
    }
    return ans;
}