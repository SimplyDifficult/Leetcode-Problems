// Sets nextRight of all nodes of a tree 
void connect(struct Node* root) 
{ 
    queue<Node*> q; 
    q.push(root); 
  
    // null marker to represent end of current level 
    q.push(NULL);  
  
    // Do Level order of tree using NULL markers 
    while (!q.empty()) { 
        Node *p = q.front(); 
        q.pop(); 
        if (p != NULL) { 
  
            // next element in queue represents next  
            // node at current Level  
            p->nextRight = q.front(); 
  
            // push left and right children of current 
            // node 
            if (p->left) 
                q.push(p->left);  
            if (p->right) 
                q.push(p->right); 
        }  
         
        // if queue is not empty, push NULL to mark  
        // nodes at this level are visited 
        else if (!q.empty())  
            q.push(NULL);  
    } 
} 
