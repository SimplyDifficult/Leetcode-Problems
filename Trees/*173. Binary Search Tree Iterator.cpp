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
class BSTIterator {
public:
    stack<TreeNode*>stack;
    
    void pushall(TreeNode* root){
        for(;root!=NULL;stack.push(root),root=root->left);
    }
    
    BSTIterator(TreeNode* root) {
       pushall(root); 
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* temp=stack.top();
        stack.pop();
        pushall(temp->right);
        return temp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
