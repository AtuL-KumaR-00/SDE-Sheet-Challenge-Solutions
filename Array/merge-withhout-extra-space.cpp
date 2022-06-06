class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long int arr1[],long long int arr2[], int n, int m)
        {   int temp,i=0,j=0,l=n-1;
            while(i<n && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[l],arr2[j]);
                    l--;
                    j++;
                }
                //else if(arr1[i]==arr2[j]){i++;}
                else { i++;}
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        }
};