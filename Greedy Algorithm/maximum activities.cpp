#include<bits/stdc++.h>

static bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) {
        /*if(a.first!=b.first)*/    return a.first<b.first;
    }
        //else return
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,int>> vec;
    for(int i=0;i<start.size();i++){
        vec.push_back({start[i],end[i]});
    }
    sort(vec.begin(),vec.end(),cmp);
    int count=1;
    int prev_end=vec[0].second;
    for(int i=1;i<vec.size();i++){
        if(vec[i].first>= prev_end){
            count++;
            prev_end=vec[i].second;
        }
    }
    return count;
}