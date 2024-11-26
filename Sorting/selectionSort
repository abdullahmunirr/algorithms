// Algorithm
// Find the minimum element from the unsorted part of the array
// swap it with the first element of the unsorted part

// Best Case: O(n^2)
// Average Case: O(n^2)
// Worst Case: O(n^2)
// (Number of comparisons is always n(n-1)/2)

// Space Complexity: O(1) (In-place sorting)

// SELECTION_SORT(A, n):
//    for i ← 0 to n-2 do
//        minIndex ← i
//        for j ← i+1 to n-1 do
//            if A[j] < A[minIndex] then
//                minIndex ← j
//            end if
//        end for
//        swap A[i] and A[minIndex]
//    end for

// When to Use:
// Small datasets.
// Limited memory environments.

#include <iostream>
using namespace std;

void selectionSort(int array[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        
        for(int j = i+1; j < size; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
