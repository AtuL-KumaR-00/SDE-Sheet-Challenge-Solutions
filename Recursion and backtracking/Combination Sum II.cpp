#include<bits/stdc++.h>
void f(int i,vector<int>&arr,int n, int target,vector<int>&contri, vector<vector<int>> &ans){
    if(target==0){
//         for(auto x:ans){
//             if(x==contri)    return;
//         }
        ans.push_back(contri);
        return;
    }
    if(target<0 || i==n)    return;
    
    
    contri.push_back(arr[i]);
    f(i+1,arr,n,target-arr[i],contri,ans);
    contri.pop_back();
    
    while(i+1<n && arr[i]==arr[i+1] )    i++;
    f(i+1,arr,n,target,contri,ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> contri;
    f(0,arr,n,target,contri,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
