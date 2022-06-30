#include<bits/stdc++.h>
bool isPal(string s){
    int lo=0;
    int hi=s.size()-1;
    while(lo<hi){
        if(s[lo]!=s[hi])    return false;
        lo++;
        hi--;
    }
    return true;
}
int f(string s,int pos,vector<int>&dp){
    if(pos==s.size()-1)    return 0;
    if(pos==s.size())    return 0;
    
    if(dp[pos]!=-1)    return dp[pos];
    int mn = INT_MAX; 
    for(int i=pos;i<s.size();i++){
        if(isPal(s.substr(pos,i-pos+1))){
            int temp=1+f(s,i+1,dp);
            if(i==s.size()-1)    temp--;
            mn=min(mn,temp);
        }
    }
    return dp[pos]=mn;
}

int palindromePartitioning(string str) {
    vector<int> dp(str.size(),-1);
    return f(str,0,dp);
}
