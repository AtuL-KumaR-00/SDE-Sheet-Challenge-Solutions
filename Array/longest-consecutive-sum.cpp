// Aproach 1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        if(nums.size()==0)  return 0;
        int res=1;
        //for(int i=0;i<nums.size();i++)  st.insert(nums[i]);
        for(int i=0;i<nums.size();i++){
            st.erase(nums[i]);
            int prev=nums[i]-1,next=nums[i]+1;
            while(st.find(prev)!=st.end()) { 
                st.erase(prev);
                prev--;
            }
            while(st.find(next)!=st.end()){
                st.erase(next);
                next++;
            }
            res=max(res,next-prev-1);
        }
        return res;
    }
};

//Approach 2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1)!=st.end()) continue;
            
            int next=nums[i]+1;
            int count=1;
            while(st.find(next)!=st.end()){
                count++;
                next++;
            }
            res=max(count,res);
        }
        return res;
    }
};