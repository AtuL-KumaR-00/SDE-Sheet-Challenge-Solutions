#include<bits/stdc++.h>

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(n+1,1000000000);
    dist[src]=0;
    pq.push({0,src});
    vector<vector<pair<int,int>>> graph(n+1);
    
    for(int i=0 ; i < edges.size() ; i++){
        graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        //graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    while(pq.empty()==false){
        int currDist=pq.top().first;
        int currNode=pq.top().second;
        pq.pop();
        
        for(pair<int,int> u:graph[currNode]){
            if(dist[u.first] > currDist + u.second){
                dist[u.first]=currDist + u.second;
                pq.push({dist[u.first],u.first});
            }
        }
    }
    return dist[dest];
}