/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* f(vector<int> &arr, int n,int lo,int hi){
    if(lo>hi)    return NULL;
    int mid = (hi+lo)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = f(arr,n,lo,mid-1);
    root->right = f(arr,n,mid+1,hi);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return f(arr,n,0,n-1);
}