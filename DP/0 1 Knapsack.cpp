#include<bits/stdc++.h>
int f(int idx, vector<int> &values, vector<int> &weights, int n, int w,int &profit){
    if(w<0 || idx>=n)    return profit;
    
    int nottake = f(idx+1,values,weights,n,w,profit);
    
    int take=0;
    if(weights[idx]<=w){
        w=w-weights[idx];
        profit += values[idx];
        take = f(idx+1,values,weights,n,w,profit);
        profit-=values[idx];
    }
    return max(nottake,take);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	int profit=0;
    return f(0,values,weights,n,w,profit);
    //return profit;
}


APPROACH 2:

