#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='M')    ans+=1000;
        else if(s[i]=='C'){
            if(i+1<n && (s[i+1]=='M' || s[i+1]=='D')){
                i++;
                if(s[i]=='M')
                    ans+=900;
                else ans+=400;
            }
            else ans+=100;
        }
        else if(s[i]=='D')    ans+=500;
        else if(s[i]=='X'){
            if(i+1<n && (s[i+1]=='C' || s[i+1]=='L')){
                i++;
                if(s[i]=='C')    ans+=90;
                else ans+= 40;
            }
            else ans+=10;
        }
        else if(s[i]=='L')    ans+=50;
        else if(s[i]=='I'){
            if(i+1<n && (s[i+1]=='V' || s[i+1]=='X')){
                i++;
                if(s[i]=='V')    ans+=4;
                else ans+=9;
            }
            else ans++;
        }
        else if(s[i]=='V') ans+=5;
    }
    return ans;
}
