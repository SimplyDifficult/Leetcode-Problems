 A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. 
 
1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.


// A utility function to store inorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storeInorder(Node* root, char arr[], int& i) 
{ 
    if (root == NULL) { 
        arr[i++] = '$'; 
        return; 
    } 
    storeInorder(root->left, arr, i); 
    arr[i++] = root->key; 
    storeInorder(root->right, arr, i); 
} 


// A utility function to store preorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storePreOrder(Node* root, char arr[], int& i) 
{ 
    if (root == NULL) { 
        arr[i++] = '$'; 
        return; 
    } 
    arr[i++] = root->key; 
    storePreOrder(root->left, arr, i); 
    storePreOrder(root->right, arr, i); 
} 


/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S) 
{ 
    /* base cases */
    if (S == NULL) 
        return true; 
    if (T == NULL) 
        return false; 
  
    // Store Inorder traversals of T and S in inT[0..m-1] 
    // and inS[0..n-1] respectively 
    int m = 0, n = 0; 
    char inT[MAX], inS[MAX]; 
    storeInorder(T, inT, m); 
    storeInorder(S, inS, n); 
    inT[m] = '\0', inS[n] = '\0'; 
  
    // If inS[] is not a substring of preS[], return false 
    if (strstr(inT, inS) == NULL) 
        return false; 
  
    // Store Preorder traversals of T and S in inT[0..m-1] 
    // and inS[0..n-1] respectively 
    m = 0, n = 0; 
    char preT[MAX], preS[MAX]; 
    storePreOrder(T, preT, m); 
    storePreOrder(S, preS, n); 
    preT[m] = '\0', preS[n] = '\0'; 
  
    // If inS[] is not a substring of preS[], return false 
    // Else return true 
    return (strstr(preT, preS) != NULL); 
} 
