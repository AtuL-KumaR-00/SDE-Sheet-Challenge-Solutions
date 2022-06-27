#include<bits/stdc++.h>

void dfs(int node, vector<vector<int>>&graph,vector<bool>&visited, int n, stack<int>&st){
    visited[node]=true;
    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && visited[i]==false){
            dfs(i,graph,visited,n, st);
        }
    }
    st.push(node);
}

void DFSrec(int node,vector<vector<int>>&graph,vector<bool>&visited,int n, vector<int>&contri){
    visited[node]=true;
    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && visited[i]==false){
            DFSrec(i,graph,visited,n,contri);
        }
    }
    contri.push_back(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]][edges[i][1]]=1;
    }
    stack<int> st;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,graph,visited,n,st);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(graph[i][j],graph[j][i]);
        }
    }
    for(int i=0;i<n;i++)    
        visited[i]=false;
    
    vector<vector<int>> ans;
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        if(visited[node]==false){
            vector<int> contri;
            DFSrec(node,graph,visited,n,contri);
            ans.push_back(contri);
        }
    }
    return ans;
}