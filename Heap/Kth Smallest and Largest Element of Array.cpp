#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i=0;i<n;i++){
        pq2.push(arr[i]);
        if(pq2.size()>k)    pq2.pop();
        
        pq1.push(arr[i]);
        if(pq1.size()>k)    pq1.pop();
        
    }
    return {pq1.top(),pq2.top()};
}