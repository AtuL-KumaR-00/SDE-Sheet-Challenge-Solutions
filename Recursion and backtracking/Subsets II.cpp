

class Solution {
public:
    void func(int idx,vector<int>&arr, vector<int> contri, vector<vector<int>>&ans){
        if(idx==arr.size()){
            //sort(contri.begin(),contri.end());
            bool found=false;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==contri)    {
                    return;
                }
            }
            ans.push_back(contri);
            return;
        }
        func(idx+1,arr,contri,ans);
        contri.push_back(arr[idx]);
        func(idx+1,arr,contri,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> contri;
        vector<vector<int>> ans;
        func(0,arr,contri,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};