#include<bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(vertices,INT_MAX);
    dist[source]=0;
    pq.push({0,source});
    vector<vector<pair<int,int>>> graph(vertices);
    
    for(int i=0 ; i < edge.size() ; i++){
        graph[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        graph[edge[i][1]].push_back({edge[i][0],edge[i][2]});
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
    return dist;
}
