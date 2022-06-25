/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void f(BinaryTreeNode<int> *root, vector<int>&vec){
    if(root==NULL)    return;
    f(root->left,vec);
    vec.push_back(root->data);
    f(root->right,vec);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> vec;
    f(root,vec);
    int i=0,j=vec.size()-1;
    while(i<j){
        if(vec[i]+vec[j]==k)    return true;
        if(vec[i]+vec[j]>k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}