// Algorithm:
// Determine the range of the input data (maximum and minimum elements).
// Create a frequency array to count occurrences of each value.
// Modify the frequency array to store cumulative counts.
// Place each element in its correct position in the output array using the cumulative counts.


// COUNTING_SORT(A, n):
//    maxElement ← max(A)
//    create array count[0..maxElement] initialized to 0
//    for i ← 0 to n-1 do
//        count[A[i]] ← count[A[i]] + 1
//    for i ← 1 to maxElement do
//        count[i] ← count[i] + count[i-1]
//    create output[0..n-1]
//    for i ← n-1 downto 0 do
//        output[count[A[i]] - 1] ← A[i]
//        count[A[i]] ← count[A[i]] - 1
//    copy output to A


// Best Case: O(n + k)
// Average Case: O(n + k)
// Worst Case: O(n + k)
// where n is the number of elements and k is the range of the input.

// Space Complexity: O(n + k) (For auxiliary arrays)

// When to Use:
// Sorting integers or characters within a small range.
// Not suitable for datasets with large ranges or floating-point numbers.

#include <iostream>
using namespace std;

void countingSort(int array[], int size)
{
    int maxElement = array[0];
    for(int i = 1; i<size; i++)
    {
        if(array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }
    
    int* count = new int[maxElement + 1]();
    
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    
    for (int i = 1; i <= maxElement; i++)
    {
        count[i] += count[i - 1];
    }
    
    int* output = new int[size];
    
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
    
    delete[] count;
    delete[] output;
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    countingSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
