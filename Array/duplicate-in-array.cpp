#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        if(st.find(arr[i])!=st.end()) return arr[i];
        else st.insert(arr[i]);
    }
    return 0;
}