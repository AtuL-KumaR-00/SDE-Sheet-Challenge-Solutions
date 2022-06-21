#include<bits/stdc++.h>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int _val){
        val=_val;
        left=NULL;
        right=NULL;
    }
};

unordered_map<int,int> mp;

TreeNode* buildTree(vector<int>& inorder, vector<int>& levelOrder, int iStart,int iEnd,int N){
    if(iStart==0 && iEnd==N-1){
        for(int i=0;i<N;i++){
            mp[levelOrder[i]]=i;
        }
    }
    
    if(iEnd>=N || iStart>=N)    return NULL;
    if(iEnd<iStart)    return NULL;
    if(iStart==iEnd){
        TreeNode* x=new TreeNode(inorder[iStart]);
        return x;
    }
    
    int inIndex = iStart;
    for (int j = iStart + 1; j <= iEnd; j++)
    {
        if (mp[inorder[j]] < mp[inorder[inIndex]])
            inIndex = j;
    }
    
    TreeNode* root = new TreeNode(inorder[inIndex]);
    
    
    root->left=buildTree(inorder,levelOrder,iStart,inIndex-1,N);
    root->right=buildTree(inorder,levelOrder,inIndex+1,iEnd,N);
    return root;
}

int height(TreeNode* root){
    if(root==NULL)    return 0;
    return 1 + max(height(root->left),height(root->right));
}

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
    TreeNode* root=buildTree(inorder,levelOrder,0,N-1,N);
    return height(root)-1;
}