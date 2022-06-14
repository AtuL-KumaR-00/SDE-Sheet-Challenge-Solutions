int search(int* arr, int n, int key) {
    // Write your code here.
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(arr[mid]==key)    return mid;
        bool first=false;
        if(arr[mid]<arr[hi]) first=true;
        if(first==true){
            if( key<=arr[hi] && key>arr[mid]){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        else {
            if( key>=arr[lo] && key<arr[mid]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }  
    }
    return -1;
}