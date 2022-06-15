#include<bits/stdc++.h>
bool isSafe(int barrier,int n, vector<int>&pos, int c){
    int co_ordi=pos[0],noOfPlayer=1;
    for(int i=1;i<n;i++){
        if(pos[i]-co_ordi>=barrier){
            noOfPlayer++;
            co_ordi=pos[i];
        }
        if(noOfPlayer>=c)    return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
    // Write your code here
    sort(positions.begin(),positions.end());
    int lo=0;
    int hi=positions[n-1]-positions[0];
    
    int res=-1;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(isSafe(mid,n,positions,c)){
            lo=mid+1;
            res=mid;
        }
        else{
            hi=mid-1;
        }
    }
    return res;
}