// First vector stores all nodes and adjacent of every  
// node in a stack. 
// Second vector stores all nodes and adjacent of every  
// node in a queue. 
bool mirrorUtil(vector<stack<int> >& tree1, 
                      vector<queue<int> >& tree2) 
{ 
    // Traversing each node in tree. 
    for (int i = 1; i < tree1.size(); ++i) { 
        stack<int>& s = tree1[i]; 
        queue<int>& q = tree2[i]; 
  
        // While stack is not empty && Queue is not empty 
        while (!s.empty() && !q.empty()) { 
  
            // checking top element of stack and front 
            // of queue. 
            if (s.top() != q.front()) 
                return false; 
  
            s.pop(); 
            q.pop(); 
        } 
  
        // If queue or stack is not empty, return false. 
        if (!s.empty() || !q.empty()) 
            return false; 
    } 
  
    return true; 
} 
