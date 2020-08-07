/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*ans;
    
    bool f(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL)return false;
        
        int x=(root==p || root==q)?1:0;
        int l=(f(root->left,p,q))?1:0;
        int r=f(root->right,p,q)?1:0;
        
        if(x+l+r>=2)ans=root;
        
        return (x+l+r)>0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f(root,p,q);
        return ans;
    }
};
