bool isSafe(int barrier,int n, vector<int>&pos, int c){
    int dist=0,noOfPlayers=1;
    for(int i=0;i<n;i++){
        if(dist + pos[i]>barrier){
            noOfPlayers++;
            dist=pos[i];
        }
        else dist+=pos[i];
    }
    if(noOfPlayers<=c)    return true;
    else return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    if(c>n) return -1;
    int lo=INT_MAX;
    int hi=0;
    for(int i=0;i<n;i++){
        lo=min(lo,positions[i]);
        hi += positions[i];
    }
    int res=-1;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(isSafe(mid,n,positions,c)){
            lo=mid+1;
            res=mid;
        }
        else{
            hi=mid-1;
        }
    }
    return res;
}