/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int> *f(vector<int> &inorder, vector<int> &preorder,int n,int pre, int iStart,int iEnd, unordered_map<int,int>&mp){
    if(pre>=n)    return NULL;
    if(iEnd>=n)    return NULL;
    if(iStart>iEnd)    return NULL;
    //if(iStart==iEnd)    return new TreeNode<int>(inorder[iStart]);
    
    TreeNode<int> *root= new TreeNode<int>(preorder[pre]);
    int idx=mp[preorder[pre]];
    root->left=f(inorder,preorder,n,pre+1,iStart,idx-1,mp);
    root->right=f(inorder,preorder,n,pre+ idx-iStart+1,idx+1,iEnd,mp);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n=inorder.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    return f(inorder,preorder,n,0,0,n-1,mp);
}