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
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(!root){
        return "";
    }
    string s = "";
    queue<TreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        q.pop();
        if(node==NULL){
            s.append("-1 ");
        }
        else{
            s.append(to_string(node->data)+" ");
        }
        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size()==0){
        return NULL;
    }
    stringstream s(serialized);
    string str;
    getline(s,str,' ');
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        getline(s,str,' ');
        if(str=="-1"){
            node->left==NULL;
        }
        else{
            TreeNode<int>* ln = new TreeNode<int>(stoi(str));
            node->left=ln;
            q.push(ln);
        }
        getline(s,str,' ');
        if(str=="-1"){
            node->right==NULL;
        }
        else{
            TreeNode<int>* rn = new TreeNode<int>(stoi(str));
            node->right=rn;
            q.push(rn);
        }        
    }
    return root;
}



