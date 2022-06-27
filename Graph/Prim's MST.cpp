#include<bits/stdc++.h>
static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second < b.second;
}
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n+1);
    for(int i = 0;i<=n;i++) 
        parent[i] = i; 
    vector<int> rank(n+1, 0); 
    
    int cost = 0;
    
    vector<pair<pair<int, int>, int>> mst;
    for(auto it : edges) {
        if(findPar(it.first.first, parent) != findPar(it.first.second, parent)) {
            cost += it.second; 
            mst.push_back({{it.first.first, it.first.second}, it.second}); 
            unionn(it.first.first, it.first.second, parent, rank); 
        }
    }
    return mst;
}
