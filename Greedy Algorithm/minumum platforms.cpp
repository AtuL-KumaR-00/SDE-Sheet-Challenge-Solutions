// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> vec;
    	for(int i=0;i<n;i++){
    	    vec.push_back({arr[i],dep[i]});
    	}
    	sort(vec.begin(),vec.end());
    	priority_queue<int,vector<int>,greater<int>> pq;
    	pq.push(vec[0].second);
    	int ans=0;
    	for(int i=1;i<n;i++){
    	    while(vec[i].first > pq.top() && !pq.empty()){
    	        pq.pop();
    	    }
    	    pq.push(vec[i].second);
    	    int temp=pq.size();
    	    ans=max(ans,temp);
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;

}  // } Driver Code Ends







APPROACH 2:

int calculateMinPatforms(int at[], int dt[], int n) {
    int i=1,j=0;
    int platform=1;
    int ans=1;
    
    sort(at,at+n);
    sort(dt,dt+n);
    
    while(i<n && j<n){
        
            if(at[i] <= dt[j])
            {
                platform++;  //one more platform needed
//                 if(ans<platform)
//                     ans=platform;
                i++;
            }
            else{
                platform--;   //one platform can be reduced
                j++;
            }
        ans=max(ans,platform);  //updating the value with the current maximum
            
        }
    return ans;
    }
    