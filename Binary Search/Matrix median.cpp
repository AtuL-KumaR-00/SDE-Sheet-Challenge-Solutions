int upper_bound(vector<int>&vec,int x){
    int lo=0;
    int hi=vec.size()-1;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(vec[mid]<=x)    lo=mid+1;
        else hi=mid-1;
    }
    return lo;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int r=matrix.size();
    int c=matrix[0].size();
    int pos=r*c/2;
    int lo=0;
    int hi=100001;
    while(lo<hi){
        int mid=(hi+lo)/2;
        int temp=0;
        for(int i=0;i<r;i++){
            temp+= upper_bound(matrix[i],mid);
        }
        //if(temp==pos)   return mid;
        if(temp>pos)   hi=mid-1;
        else lo=mid+1;
    }
    return lo;
}