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
    
    vector<int>ans;
    
    void f(TreeNode* root,int depth){
        if(root==NULL)return;
        if(ans.size()==depth)ans.push_back(root->val);
        f(root->right,depth+1);
        f(root->left,depth+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        f(root,0);
        return ans;
    }
};
