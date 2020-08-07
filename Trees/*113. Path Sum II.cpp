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
    vector<vector<int>>ans;
    
    void f(TreeNode*root,int sum,vector<int>path){
        if(root==NULL)return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==root->val)ans.push_back(path);
        f(root->left,sum-root->val,path);
        f(root->right,sum-root->val,path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>path;
        f(root,sum,path);
        return ans;
    }
};
