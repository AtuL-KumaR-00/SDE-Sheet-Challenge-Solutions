class Solution {
public:
    vector<vector<int>> generate(int k) {
        vector<vector<int>> ans;
        
        if(k==1) return {{1}};
        ans.push_back({1});
        ans.push_back({1,1});
        
        for(int i=2;i<k;i++){
            vector<int> contri;
            contri.push_back(1);
            for(int j=1;j<ans[ans.size()-1].size();j++){
                contri.push_back(ans[ans.size()-1][j-1]+ans[ans.size()-1][j]);
            }
            contri.push_back(1);
            ans.push_back(contri);
        }
        return ans;
    }
};