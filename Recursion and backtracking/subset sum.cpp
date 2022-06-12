//vector<int> ans={};
vector<int> subsum(int idx, int curr_sum,vector<int>&num){
    if(idx==num.size()-1) return {0,num[idx]};
    
    vector<int> temp=subsum(idx+1,curr_sum,num);
    vector<int> temp2=temp;
    for(int i=0;i<temp2.size();i++){
        temp2[i]+=num[idx];
        temp.push_back(temp2[i]);
    }
    return temp;
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans=subsum(0,0,num);
    sort(ans.begin(),ans.end());
    return ans;
}




APPROACH 2:

void subsum(int idx,int curr_sum,vector<int>&nums,vector<int>&ans){
    if(idx==nums.size()){
        ans.push_back(curr_sum);
        return;
    }
    curr_sum+=nums[idx];
    subsum(idx+1,curr_sum,nums,ans);
    curr_sum-=nums[idx];
    subsum(idx+1,curr_sum,nums,ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    subsum(0,0,num, ans);
    sort(ans.begin(),ans.end());
    return ans;
}