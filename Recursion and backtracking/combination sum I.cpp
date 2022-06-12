class Solution {
public:
    // 3 types of parameters
    // Problem representation
    // Contribution
    // Result passed by reference
    void f(vector<int>& candidates, int start, int end, int target, vector<int>& contri, vector<vector<int>>& res) {
        // Base step
        if(target == 0){
            res.push_back(contri);
            return;
        }
            
        if(target < 0 || start > end)
            return;
        
        // Recursive step
        // Not include the first element at all
        f(candidates, start+1, end, target, contri, res);
        
        // Include the first element at least once
        contri.push_back(candidates[start]);
        f(candidates, start, end, target-candidates[start], contri, res);
        contri.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> contri;
        
        f(candidates, 0, candidates.size()-1, target, contri, res);
        
        return res;
    }
};