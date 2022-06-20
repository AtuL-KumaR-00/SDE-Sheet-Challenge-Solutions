/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)    return 0;
        queue<pair<TreeNode*,long long int>> q;
        long long int ans=0;
        q.push({root,0});
        
        while(!q.empty()){
            long long int n=q.size();
            long long int mmin=q.front().second;
            long long int first,last;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                long long int cur_idx=q.front().second-mmin;
                q.pop();
                if(i==0)    first=cur_idx;
                if(i==n-1)  last=cur_idx;
                if(curr->left)    q.push({curr->left,cur_idx*2+1});
                if(curr->right)    q.push({curr->right,cur_idx*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};