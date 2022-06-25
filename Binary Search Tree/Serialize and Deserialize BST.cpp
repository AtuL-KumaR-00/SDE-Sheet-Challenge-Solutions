/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root,s);
        //cout<<s;
        return s;
    }
    void preorder(TreeNode* root, string &s){
        if(root==NULL)  return;
        
        s+=to_string(root->val)+"-";
        preorder(root->left,s);
        preorder(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string item;
        TreeNode* root=NULL;
        for(int i=0;i<data.size();i++){
            if(data[i]!='-')    item+=data[i];
            else {
                cout<<stoi(item)<<" ";
                insert(root,stoi(item));
                item="";
            }
        }
        //addNode(root,5);
        return root;
    }
    
    void insert(TreeNode* &root, int val) {
        if (root == NULL) {
			root = new TreeNode(val);
			return;
		}
    
		if (val<=root->val)
			insert(root->left,val);
    
		else
			insert(root->right,val);
    
		//return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;