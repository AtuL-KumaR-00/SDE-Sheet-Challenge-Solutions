class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int k=image[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        visited[sr][sc]=true;
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        
        
        while(q.empty()==false){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int l=0;l<4;l++){
                int new_i= i + dir[l].first;
                int new_j= j + dir[l].second;
                if(new_i>=0 && new_i<image.size() && new_j>=0 && new_j<image[0].size() && visited[new_i][new_j] ==false && image[new_i][new_j]==k){
                    q.push({new_i,new_j});
                    visited[new_i][new_j]=true;
                    image[new_i][new_j]=color;
                }
                
            }
        }
        return image;
    }
};