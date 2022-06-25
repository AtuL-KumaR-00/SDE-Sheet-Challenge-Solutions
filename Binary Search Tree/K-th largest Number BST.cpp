/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void f(TreeNode<int>* root, int k,int &cnt,int &ans){
    if(root==NULL)    return;
    
    f(root->right,k,cnt,ans);
    cnt++;
    if(cnt==k)    {
        ans=root->data;
        return;
    }
    f(root->left,k,cnt,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int cnt=0;
    int ans=-1;
    f(root,k,cnt,ans);
    return ans;
}
