A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) 
than the values in its two children nodes. The former is called as max heap and the latter is called min heap. 
The heap can be represented by binary tree or array.
If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2 (assuming the indexing starts at 0).
The heapification must be performed in the bottom up order.
  
Arr[(i-1)/2] 	Returns the parent node
Arr[(2*i)+1] 	Returns the left child node
Arr[(2*i)+2] 	Returns the right child node

getMini(): It returns the root element of Min Heap O(1).
extractMin(): Removes the minimum element from MinHeap. O(Logn) 
insert(): Inserting a new key takes O(Logn) time


// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}


// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}
