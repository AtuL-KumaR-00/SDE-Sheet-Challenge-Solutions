bool isPossible(int barrier,vector<int>&A,int B){
    int noStudents=1;
    int pages=0;
    for(int i=0;i<A.size();i++){
        
        if(A[i]>barrier) return false;
        
        if(A[i]+pages > barrier){
            noStudents++;
            pages=A[i];
        }
        
        else{
            pages+=A[i];
        }
    }
    if(noStudents>B)return false;
    return true;
}



int Solution::books(vector<int> &A, int B) {
    if(A.size()<B) return -1;
    int low=INT_MAX;
    int hi=0;
    for(int i=0;i<A.size();i++){
        hi+=A[i];
        low=min(low,A[i],comp);
    }
    int res=-1;
    while(low<=hi){
        int mid=(hi+low)/2;
        if(isPossible(mid,A,B)){
            res=mid;
            hi=mid-1;
        }else low=mid+1;
    }
    return res;
}
