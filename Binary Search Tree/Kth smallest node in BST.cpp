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
void f(TreeNode<int>* root, int k,int &cnt,int &ans){
    if(root==NULL)    return;
    
    f(root->left,k,cnt,ans);
    cnt++;
    if(cnt==k)    {
        ans=root->data;
        return;
    }
    f(root->right,k,cnt,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int cnt=0;
    int ans=-1;
    f(root,k,cnt,ans);
    return ans;
}