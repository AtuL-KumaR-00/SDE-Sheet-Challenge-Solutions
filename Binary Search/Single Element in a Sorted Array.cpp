int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    //unordered_set<int> st;
    int lo=0;
    int hi=n-1;
    if(arr[0]!=arr[1]) return arr[0];
    while(lo<=hi){
        int mid=(lo+hi)/2;
        //if(arr[mid]!=arr[mid+1])    return arr[mid];
        if((mid%2==0 && arr[mid]!=arr[mid+1]) || (mid%2==1 && arr[mid]!=arr[mid-1] )){
            hi=mid-1;
        }else lo=mid+1;
    }
    return arr[lo];
}
