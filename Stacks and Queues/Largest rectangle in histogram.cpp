class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> lefts(n);
        vector<int> rights(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()==false)   rights[i]=st.top()-1;
            else    rights[i]=n-1;
            st.push(i);
        }
        //for(int i=0;i<n;i++)    cout<<rights[i]<<" ";
        //cout<<"\n";
        st=stack<int>();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty())  lefts[i]=0;
            else lefts[i]=st.top()+1;
            st.push(i);
            ans=max(ans,(rights[i]-lefts[i]+1)*heights[i]);
        }
        //for(int i=0;i<n;i++)    cout<<lefts[i]<<" ";
        
        // for(int i=0;i<n;i++){
        //     ans=max(ans,(rights[i]-lefts[i]+1)*heights[i]);
        // }
        return ans;
    }
};