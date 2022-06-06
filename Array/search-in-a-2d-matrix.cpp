class Solution {
public:
    
    int binarySearch(vector<vector<int>>&matrix, int target,int lo,int hi){
        //int n=matrix.size();
        //if(lo>hi) return ;
        if(lo==hi) return lo;
        int mid=(hi+lo)/2;
        if(matrix[mid][0]==target)return mid;
        else if(matrix[mid][0]>target)  return binarySearch(matrix,target,lo,mid);
        else return binarySearch(matrix,target,mid+1,hi);
    }
    bool found(vector<int> &nums, int target,int lo,int hi){
        if(lo>hi) return false;
        if(lo==hi) return nums[lo]==target;
        int mid=(hi+lo)/2;
        if(nums[mid]==target) return true;
        else if(nums[mid]>target) return found(nums,target,lo,mid-1);
        else return found(nums,target,mid+1,hi);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x=binarySearch(matrix,target,0,matrix.size()-1);
        if(matrix[x][0]>target && x>0) x--;
        cout<<x;
        return found(matrix[x],target,0,matrix[x].size()-1);
    }
};