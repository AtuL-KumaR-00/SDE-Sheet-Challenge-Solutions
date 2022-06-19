#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    unordered_map<char,int> mp;
    if(str1.size()!=str2.size())    return false;
    for(int i=0;i<str1.size();i++){
        mp[str1[i]]++;
        mp[str2[i]]--;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second!=0)    return false;
    }
    return true;
}