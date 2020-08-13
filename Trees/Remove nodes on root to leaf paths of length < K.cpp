// Utility method that actually removes the nodes which are not 
// on the pathLen >= k. This method can change the root as well. 
Node *removeShortPathNodesUtil(Node *root, int level, int k) 
{ 
    //Base condition 
    if (root == NULL) 
        return NULL; 
  
    // Traverse the tree in postorder fashion so that if a leaf 
    // node path length is shorter than k, then that node and 
    // all of its descendants till the node which are not 
    // on some other path are removed. 
    root->left = removeShortPathNodesUtil(root->left, level + 1, k); 
    root->right = removeShortPathNodesUtil(root->right, level + 1, k); 
  
    // If root is a leaf node and it's level is less than k then 
    // remove this node. 
    // This goes up and check for the ancestor nodes also for the 
    // same condition till it finds a node which is a part of other 
    // path(s) too. 
    if (root->left == NULL && root->right == NULL && level < k) 
    { 
        delete root; 
        return NULL; 
    } 
  
    // Return root; 
    return root; 
} 
  
// Method which calls the utitlity method to remove the short path 
// nodes. 
Node *removeShortPathNodes(Node *root, int k) 
{ 
    int pathLen = 0; 
    return removeShortPathNodesUtil(root, 1, k); 
} 
