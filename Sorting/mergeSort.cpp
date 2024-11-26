// Algorithm:
// Divide the array into two halves.
// Sort each half recursively.
// Merge the sorted halves.

// MERGE(A, left, mid, right):
//    n1 ← mid - left + 1
//    n2 ← right - mid
//    create arrays L[0..n1-1] and R[0..n2-1]
//    for i ← 0 to n1-1 do
//        L[i] ← A[left + i]
//    for j ← 0 to n2-1 do
//        R[j] ← A[mid + 1 + j]
//    i ← 0, j ← 0, k ← left
//    while i < n1 and j < n2 do
//        if L[i] ≤ R[j] then
//            A[k] ← L[i]
//            i ← i + 1
//        else
//            A[k] ← R[j]
//            j ← j + 1
//        end if
//        k ← k + 1
//    end while
//    copy remaining elements of L, if any
//    copy remaining elements of R, if any

// Best Case: O(n \log n)
// Average Case: O(n \log n)
// Worst Case: O(n \log n)

// Space Complexity: O(n) (Auxiliary array for merging)

// When to Use:
// Sorting large datasets.
// Stable sort requirements.

#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    
    int L[n1];
    int R[n2];
    
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        R[i] = array[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2)
    {
        array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    
    while (i < n1)
    {
        array[k++] = L[i++];
    }
    
    while (j < n2)
    {
        array[k++] = R[j++];
    }
}

void mergeSort(int array[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
