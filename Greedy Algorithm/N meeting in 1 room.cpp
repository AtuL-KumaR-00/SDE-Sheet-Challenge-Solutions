#include <bits/stdc++.h>
struct meeting{
    int start;
    int end;
    int pos;
};

static bool cmp(struct meeting m1, struct meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    else return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<meeting> vec;
    //unordered_map<pair<int,int>,int,hash_pair> mp;
    for(int i=0;i<start.size();i++){
        vec.push_back({start[i],end[i],i+1});
        //mp[{start[i],end[i]}]=i+1;
    }
    sort(vec.begin(),vec.end(),cmp);
    vector<int> ans;
    ans.push_back(vec[0].pos);
    int ending=vec[0].end;
    for(int i=1;i<vec.size();i++){
        if(ending<vec[i].start){
            ans.push_back(vec[i].pos);
            ending=vec[i].end;
        }
    }
    return ans;
}