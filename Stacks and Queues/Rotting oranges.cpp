class Solution {
public:
    int t=0;
    int good=0;
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    
    void BFS(vector<pair<int,int>>&rotten,vector<vector<int>>&grid,int n,int m){
        t=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<rotten.size();i++){
            q.push({rotten[i].first,rotten[i].second});
        }
        
        while(!q.empty()){
            int k=q.size();
            good+=k;
            while(k--){
                pair<int,int> curr=q.front();
                q.pop();
                for(int i=0;i<dir.size();i++){
                    int new_i=curr.first+dir[i].first;
                    int new_j=curr.second+dir[i].second;
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && visited[new_i][new_j]==false && grid[new_i][new_j]==1){
                        visited[new_i][new_j]=true;
                        q.push({new_i,new_j});
                    }
                }
            }
            if(q.empty()==false)    t++;
        }
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        int x,y;
        vector<pair<int,int>> rotten;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)    {
                if(grid[i][j]==2){
                    rotten.push_back({i,j});
                }
                if(grid[i][j]!=0)  count++;
            }
        }
        BFS(rotten,grid,n,m);
        if(good==count) return t;
        else    return -1;
    }
};