/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool f(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1==NULL && root2==NULL)    return true;
    if((root1==NULL && root2!=NULL) ||(root1!=NULL && root2==NULL))    
        return false;
    if(root1->data != root2->data)    return false;
    return f(root1->left,root2->right)&&f(root1->left,root2->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    if(!root)    return true;
    if((!root->left && root->right) || (!root->right && root->left))    
        return false; 
    return f(root->left,root->right);
}