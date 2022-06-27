#include<bits/stdc++.h>

bool bipartiteBFS(int node,vector<vector<int>>&graph,vector<int>&color,int v){
    queue<int> q;
    q.push(node);
    color[node]=0;
    while(!q.empty()){
        int curr=q.front();
        int curr_color=color[curr];
        q.pop();
        for(int u:graph[curr]){
            if(color[u]==-1){
                q.push(u);
                if(curr_color==1)    color[u]=2;
                else    color[u]=1;
            }
            else{
                if(color[u]==curr_color)    return false;
            }
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int v=edges.size();
    vector<vector<int>> graph(v);
    for(int i=0 ; i<v ; i++){
        for(int j=0;j<v;j++){
            if(edges[i][j]==1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<int> color(v,-1);
    
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(!bipartiteBFS(i,graph,color,v))
                return false;
        }
    }
    return true;
}