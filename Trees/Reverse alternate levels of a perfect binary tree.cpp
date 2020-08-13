void preorder(struct Node *root1, struct Node* root2, int lvl) 
{ 
    // Base cases 
    if (root1 == NULL || root2==NULL) 
        return; 
  
    // Swap subtrees if level is even 
    if (lvl%2 == 0) 
        swap(root1->key, root2->key); 
  
    // Recur for left and right subtrees (Note : left of root1 
    // is passed and right of root2 in first call and opposite 
    // in second call. 
    preorder(root1->left, root2->right, lvl+1); 
    preorder(root1->right, root2->left, lvl+1); 
} 
  
// This function calls preorder() for left and right children 
// of root 
void reverseAlternate(struct Node *root) 
{ 
   preorder(root->left, root->right, 0); 
} 
