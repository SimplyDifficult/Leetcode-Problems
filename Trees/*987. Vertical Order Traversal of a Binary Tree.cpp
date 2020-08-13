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
    map<int,vector<int>>mp;
        
    void f(TreeNode*root,int col){
        if(root==NULL)return;
        mp[col].push_back(root->val);
        f(root->left,col-1);
        f(root->right,col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        f(root,0);
        vector<vector<int>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
