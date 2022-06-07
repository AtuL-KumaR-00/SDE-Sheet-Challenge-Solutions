class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int b=target-nums[i];
            if(mp.find(b)!=mp.end()){
                return {mp[b],i};
            }
            else mp[nums[i]]=i;
        }
        return {};
    }
};