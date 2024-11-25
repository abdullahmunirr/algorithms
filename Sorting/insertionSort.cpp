// Algorithm

// Traverse array from 2nd element to the last
// Compare current element in sorted position of array
// Insert it at the correct position

// INSERTION_SORT(A, n):
// for i ← 1 to n-1 do
//    key ← A[i]
//    j ← i - 1
// while j >= 0 and A[j] > key do
//        A[j + 1] ← A[j]
//        j ← j - 1
//    end while
//    A[j + 1] ← key
// end for

// Best Case: O(n) (Array already sorted)
// Average Case: O(n^2)
// Worst Case: O(n^2) (Array sorted in reverse order)

// Space Complexity: O(1) (In-place sorting)

// When to use
// Small datasets
// Almost sorted arrays (adaptive nature).

#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    for(int i = 1; i<size; i++)
    {
        int key = array[i];
        int j = i - 1;
        
        while(j > 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        
        array[j+1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
