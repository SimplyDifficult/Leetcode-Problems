bool isFullTree (struct Node* root) 
{ 
    // If empty tree 
    if (root == NULL) 
        return true; 
   
    // If leaf node 
    if (root->left == NULL && root->right == NULL) 
        return true; 
   
    // If both left and right are not NULL, and left & right subtrees 
    // are full 
    if ((root->left) && (root->right)) 
        return (isFullTree(root->left) && isFullTree(root->right)); 
   
    // We reach here when none of the above if conditions work 
    return false; 
} 
