// Algorithm:

// Pick a pivot element.
// Partition the array such that elements less than pivot are on the left, and greater ones are on the right.
// Recursively sort the partitions.

// PARTITION(A, low, high):
//    pivot ← A[high]
//    i ← low - 1
//    for j ← low to high-1 do
//        if A[j] < pivot then
//            i ← i + 1
//            swap A[i] and A[j]
//        end if
//    end for
//    swap A[i+1] and A[high]
//    return i+1
// QUICK_SORT(A, low, high):
//    if low < high then
//        pi ← PARTITION(A, low, high)
//        QUICK_SORT(A, low, pi-1)
//        QUICK_SORT(A, pi+1, high)

// Best Case: O(n \log n)
// Average Case: O(n \log n)
// Worst Case: O(n^2) (Occurs when pivot is always the smallest or largest)

// Space Complexity: O(\log n) (Recursive calls)

// When to Use:
// Large datasets with limited memory.
// Faster than merge sort for in-place sorting.

#include <iostream>
using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++)
    {
        if(array[j] < pivot)
        {
            swap(array[++i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    
    return i+1;
}

void quickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
