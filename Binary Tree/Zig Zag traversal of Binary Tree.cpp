/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(root==NULL)    return {};
    queue<BinaryTreeNode<int> *>q;
    bool flag=false;
    vector<int> ans;
    q.push(root);
    while(q.empty()==false){
        int n=q.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> *curr=q.front();
            q.pop();
            if(flag==false){
                ans.push_back(curr->data);
            }
            else{
                st.push(curr->data);
            }
            if(curr->left)    q.push(curr->left);
            if(curr->right)    q.push(curr->right);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        flag=!flag;
    }
    return ans;
}
