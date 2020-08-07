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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>stack;
        TreeNode*curr=root;
        while(curr!=NULL||!stack.empty()){
            while(curr!=NULL){
                stack.push(curr);
                curr=curr->left;
            }
            curr=stack.top();
            stack.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};



/*class Solution {
public:
    
    void f(TreeNode* root,vector<int>& ans){
        if(root!=NULL){
            if(root->left!=NULL)
                f(root->left,ans);
            ans.push_back(root->val);
            if(root->right!=NULL)
                f(root->right,ans);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        f(root,ans);
        return ans;
        
    }
};*/
