#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=st.top()){
            st.pop();
        }
        if(!st.empty())    ans[i]=st.top();
        else ans[i]=-1;
        st.push(arr[i]);
    }
    return ans;
}