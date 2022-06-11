#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.begin()+n);
    for(int i=0;i<n;i++){
        int j=i+1,k=n-1;
        while(j<k){
            if(arr[j]+arr[i]+arr[k]==K){
                bool found=false;
                vector<int> contri={arr[i],arr[j],arr[k]};
                if(found==false) ans.push_back(contri);
                int x=arr[j];
                int y=arr[k];
                while(j<k && arr[j]==x){
                   j++ ;
                }
                while(j<k && arr[k]==y){
                   k-- ;
                }
            }
            else if(arr[i]+arr[j]+arr[k]>K){
                k--;
            }else{
                j++;
            }
        }
        while(i+1<n && arr[i]==arr[i+1]){
           i++ ;
       }
    }
    return ans;
}