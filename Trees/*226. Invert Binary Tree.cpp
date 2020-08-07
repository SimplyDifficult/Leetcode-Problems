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
    
    TreeNode*f(TreeNode*root){
        if(root==NULL)return NULL;
        TreeNode*l=f(root->left);
        TreeNode*r=f(root->right);
        root->right=l;
        root->left=r;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return f(root);
    }
};
