The distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as 
the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.


1.  Create a recursive function that takes a node and the two values n1 and n2.
2.  If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
3.  If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
4.  If both the above cases are false then return the current node as LCA.


/* Function to find LCA of n1 and n2.  
The function assumes that both  
n1 and n2 are present in BST */
node *lca(node* root, int n1, int n2)  
{  
    if (root == NULL) return NULL;  
  
    // If both n1 and n2 are smaller 
    // than root, then LCA lies in left  
    if (root->data > n1 && root->data > n2)  
        return lca(root->left, n1, n2);  
  
    // If both n1 and n2 are greater than  
    // root, then LCA lies in right  
    if (root->data < n1 && root->data < n2)  
        return lca(root->right, n1, n2);  
  
    return root;  
}
