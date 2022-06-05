#include <bits/stdc++.h> 
void sort012(int *A, int n)
{
   //   Write your code here
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[A[i]]++;
    }
    int i;
    //int ans[];
    int x=0;
    for(i=0;i<mp[0];i++){
        A[x]=0;
        x++;
    }
    int j;
    for( j=0;j<mp[1];j++){
        A[x]=1;
        x++;
    }
    for(int k=0;k<mp[2];k++){
        A[x]=2;
        x++;
    }
    //A=ans;
}