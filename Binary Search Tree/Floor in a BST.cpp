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
int pre(TreeNode<int>* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root->val;
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int prev=INT_MIN;
    while(root){
        if(root->val==X){
            return X;
        }
        else if(root->val > X){
            root=root->left;
        }
        else{
            prev=root->val;
            root=root->right;
        }
    }
    return prev;
}