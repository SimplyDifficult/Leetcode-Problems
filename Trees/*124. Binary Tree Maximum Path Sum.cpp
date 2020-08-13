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
    
    int ans=INT_MIN;
    
    int maxi(TreeNode*root){
        if(root==NULL)return 0;
        int l=maxi(root->left),r=maxi(root->right);
        int v=root->val;
        ans=max(ans,max(v,max(v+l,max(v+r,v+l+r))));
        return max(v,v+max(l,r));
    }
    
    int maxPathSum(TreeNode* root) {
        maxi(root);
        return ans;
    }
};
