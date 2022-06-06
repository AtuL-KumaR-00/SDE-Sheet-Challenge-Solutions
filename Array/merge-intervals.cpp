class Solution {
public:

    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int m= intervals.size();
        int n= intervals[0].size();
        vector<vector<int>> ans;
        
        int i=0;
        while(i < m){
            int start = intervals[i][0];
            int end= intervals[i][1];
            while(i+1< m && end>=intervals[i+1][0]){
                end=max(end,intervals[i+1][1]);
                i++;
            }
            i++;
            ans.push_back({start,end});
            
        }
        return ans;
    }
        
    
};