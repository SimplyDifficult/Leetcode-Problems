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
    
    map<TreeNode*,TreeNode*>parent;
    set<TreeNode*>visited;
    vector<int>ans;

    void findparent(TreeNode*node){
        if(node==NULL)return;
        if(node->left){
            parent[node->left]=node;
            findparent(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            findparent(node->right);
        }
    }

    void dfs(TreeNode*target,int k){
        if(visited.find(target)!=visited.end())return;
        
        visited.insert(target);

        if(k==0){ans.push_back(target->val);return;}

        if(target->left){dfs(target->left,k-1);}
        if(target->right){dfs(target->right,k-1);}
        TreeNode*p=parent[target];
        if(p)dfs(p,k-1);

    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root==NULL)return {};
        findparent(root);
        dfs(target,K);
        return ans;
    }
};
