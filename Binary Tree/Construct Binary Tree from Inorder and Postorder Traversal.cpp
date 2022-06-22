/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* f(vector<int>& inOrder, vector<int>& postOrder,int li,int hi,int lp,int hp,unordered_map<int,int> &mpp){
    if(lp<0 || lp>hp)return NULL;
//     cout<<postOrder[hp]<<endl;
    int rootData=postOrder[hp];
    
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int index = mpp[rootData];
    int numLeft=lp+index-li;
    root->left=f(inOrder,postOrder,li,index-1,lp,numLeft-1,mpp);
    root->right=f(inOrder,postOrder,index+1,hi,numLeft,hp-1,mpp);
    return root;
    
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int n=postOrder.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inOrder[i]]=i;
    }
    return f(inOrder, postOrder,0,n-1,0,n-1,mp);
}
