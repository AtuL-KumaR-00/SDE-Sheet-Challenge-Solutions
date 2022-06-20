#include<bits/stdc++.h>
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
void path(TreeNode<int> *root, int x, vector<int>&contri){
    if(root==NULL)    return;
    if(root->data==x){
        contri.push_back(root->data);
        return;
    }
    contri.push_back(root->data);
    path(root->left,x,contri);
    path(root->right,x,contri);
    if(contri[contri.size()-1]!=x){
        contri.pop_back();
    }
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> contri;
    path(root,x,contri);
    return contri;
}
