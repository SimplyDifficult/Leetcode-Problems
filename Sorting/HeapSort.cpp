A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) 
than the values in its two children nodes. The former is called as max heap and the latter is called min heap. 
The heap can be represented by binary tree or array.
If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2 (assuming the indexing starts at 0).
The heapification must be performed in the bottom up order.
