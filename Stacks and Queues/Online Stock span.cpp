#include<bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>st;
    vector<int> ans;
    for(int i=0;i<price.size();i++){
        int temp=0;
        while(!st.empty() && price[i]>=st.top().first){
            temp+=st.top().second;
            st.pop();
        }
        ans.push_back(temp+1);
        st.push({price[i],temp+1});
    }
    return ans;
}