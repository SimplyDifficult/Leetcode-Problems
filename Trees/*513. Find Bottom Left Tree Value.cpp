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
    
    void f(TreeNode*root,int& vali,int depth,int& maxdepth){
        if(root==NULL)return;
        
         if(depth>maxdepth){
            maxdepth=depth;
            vali=root->val;
        }
        
        f(root->left,vali,depth+1,maxdepth);
        f(root->right,vali,depth+1,maxdepth);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int vali=0;
        int maxdepth=0;
        f(root,vali,1,maxdepth);
        return vali;
    }
};
