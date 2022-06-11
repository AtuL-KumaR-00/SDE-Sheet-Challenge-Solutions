#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.l
    long pre[n];
    long suff[n];
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        if(pre[i-1]<arr[i])    pre[i]=arr[i];
        else pre[i]=pre[i-1];
    }
    suff[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(suff[i+1]<arr[i])    suff[i]=arr[i];
        else suff[i]=suff[i+1];
    }
    long ans=0;
    for(int i=0;i<n;i++){
        ans+= min(pre[i],suff[i])-arr[i];
    }
    return ans;
}