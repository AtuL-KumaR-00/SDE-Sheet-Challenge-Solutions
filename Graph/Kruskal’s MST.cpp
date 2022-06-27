#include<bits/stdc++.h>

static bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int findParent(int u, vector<int>&parent){
    if(parent[u]==u)    
        return u;
    else return parent[u] = findParent(parent[u],parent);
}

void unionn(int u,int v, vector<int>&parent,vector<int>&rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(),graph.end(),cmp);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    vector<int> rank(n+1,0);
    
    int cost=0;
    for(auto it : graph){
        if(findParent(it[0],parent) != findParent(it[1],parent)){
            cost+=it[2];
            unionn(it[0],it[1],parent,rank);
        }
    }
    return cost;
}