#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.empty()==false && arr[i]>=st.top()){
            st.pop();
        }
        if(st.empty())    ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}