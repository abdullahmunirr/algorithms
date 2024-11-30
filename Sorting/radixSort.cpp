// Algorithm:
// Perform counting sort for each digit, starting from the least significant to the most significant.
// Use a stable sorting algorithm (like Counting Sort) for each pass.


// RADIX_SORT(A, n):
//    maxElement ← max(A)
//    exp ← 1
//    while maxElement / exp > 0 do
//        COUNTING_SORT_FOR_RADIX(A, n, exp)
//        exp ← exp * 10

// COUNTING_SORT_FOR_RADIX(A, n, exp):
//    create array count[0..9] initialized to 0
//    for i ← 0 to n-1 do
//        index ← (A[i] / exp) % 10
//        count[index] ← count[index] + 1
//    for i ← 1 to 9 do
//        count[i] ← count[i] + count[i-1]
//    create output[0..n-1]
//    for i ← n-1 downto 0 do
//        index ← (A[i] / exp) % 10
//        output[count[index] - 1] ← A[i]
//        count[index] ← count[index] - 1
//    copy output to A

// Best Case: O(d.(n+k)
// Average Case: O(d.(n+k)
// Worst Case: O(d.(n+k)
// where d is the number of digits, n is the number of elements, and k is the base.

// Space Complexity: O(n + k) (For auxiliary arrays)

// When to Use:
// Sorting integers with multiple digits.
// Efficient for datasets with a fixed digit length.

#include <iostream>
using namespace std;

void countingSortForRadix(int array[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int index = (array[i] / exp) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int array[], int size)
{
    int maxElement = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }

    for (int exp = 1; maxElement / exp > 0; exp *= 10)
    {
        countingSortForRadix(array, size, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    radixSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
