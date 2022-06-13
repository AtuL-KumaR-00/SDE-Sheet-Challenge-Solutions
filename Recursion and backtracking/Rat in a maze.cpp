// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++



class Solution{
    public:
    
    
    void dfs(int i,int j,vector<vector<int>> &m, int n, string &contri, vector<string> &ans, vector<vector<bool>>&visited){
        if(i==n-1 && j==n-1){
            ans.push_back(contri);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n) return;
        
        visited[i][j]=true;
        if(j+1<=n-1 && m[i][j+1]==1 && !visited[i][j+1]){
            contri.push_back('R');
            dfs(i,j+1,m,n,contri,ans,visited);
            contri.pop_back();
        }
        if(j-1>=0 && m[i][j-1]==1 && !visited[i][j-1]){
            contri.push_back('L');
            dfs(i,j-1,m,n,contri,ans,visited);
            contri.pop_back();
        }
        if(i+1<=n-1 && m[i+1][j]==1 && !visited[i+1][j]){
            contri.push_back('D');
            dfs(i+1,j,m,n,contri,ans,visited);
            contri.pop_back();
        }
        if(i-1>=0 && m[i-1][j]==1 && !visited[i-1][j]){
            contri.push_back('U');
            dfs(i-1,j,m,n,contri,ans,visited);
            contri.pop_back();
        }
        visited[i][j]=false;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0)  return {"-1"};
        string contri="";
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        dfs(0,0,m,n,contri,ans,visited);
        if(ans.size()==0) return {"-1"};
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends