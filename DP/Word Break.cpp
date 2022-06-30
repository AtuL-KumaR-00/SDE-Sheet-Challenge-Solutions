#include<bits/stdc++.h>
bool f(string &target,int pos, unordered_set<string>&st,vector<int>&dp){
    if(pos==target.size())    return true;
    
    if(dp[pos]!=-1)    return dp[pos];
    for(int i=pos;i<target.size();i++){
        if(st.find(target.substr(pos,i-pos+1))!=st.end() && f(target,i+1,st,dp))
            return dp[pos]=true;
    }
    return dp[pos]=false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> st;
    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);
    }
    vector<int> dp(target.size(),-1);
    return f(target,0,st,dp);
}