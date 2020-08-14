Partition Algorithm:
We start from the leftmost element and keep track of index of smaller (or equal to) elements as i. 
While traversing, if we find a smaller element, we swap current element with arr[i]. Otherwise we ignore current element.

// Standard partition process of QuickSort().  It considers the last 
// element as pivot and moves all smaller element to left of it 
// and greater elements to right 
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 


/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

T(n) = T(k) + T(n-k-1) + \theta(n)
Worst Case:  T(n) = T(n-1) + \theta(n) -- \theta(n2).
Best Case:  T(n) = 2T(n/2) + \theta(n) ---\theta(nLogn)
