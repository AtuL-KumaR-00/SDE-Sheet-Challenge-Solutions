#include<bits/stdc++.h>
int f(int i,int j,string s1,string s2, vector<vector<int>>&dp){
    if(i==-1)
        return j+1;
    if(j==-1)    return i+1;
    
    if(dp[i][j]!=-1)    return dp[i][j];
    
    if(s1[i]==s2[j])    return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    else{
        s1.push_back(s2[j]);
        int insert= 1+f(i,j-1,s1,s2,dp);
        s1.pop_back();
        
        s1[i]=s2[j];
        int replace= 1+f(i-1,j-1,s1,s2,dp);
        
        s1.pop_back();
        int del = 1+f(i-1,j,s1,s2,dp);
        return dp[i][j]=min(insert,min(replace,del));
    }
}

int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
    return f(str1.size()-1,str2.size()-1,str1,str2,dp);
}


Approach 2:

#include<bits/stdc++.h>
int f(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
    if(i==-1)
        return j+1;
    if(j==-1)    return i+1;
    
    if(dp[i][j]!=-1)    return dp[i][j];
    
    if(s1[i]==s2[j])    return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    else{
        return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp), min(f(i,j-1,s1,s2,dp), f(i-1,j-1,s1,s2,dp)));
    }
}

int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
    return f(str1.size()-1,str2.size()-1,str1,str2,dp);
}

