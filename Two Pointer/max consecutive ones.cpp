int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    vector<int> pre(n);
    int temp=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) {temp++; pre[i]=temp;}
        else pre[i]=temp;
    }
//     for(int i=0;i<n;i++) cout<<pre[i]<<" ";
//     cout<<"\n";
    if(pre[n-1]<=k) return n;
    int i=0,j=0;
    int ans=0;
    while(j<n && i<n){
        if(pre[j]-pre[i]<=k)   {
            j++;
        }
        else {
            //i++;
            ans=max(ans,j-i-1);
            while(pre[i]==pre[i+1]) i++;
            i++;
        }
    }
    return ans;
}
