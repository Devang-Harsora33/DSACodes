// InsertionSort Time Complexity = O(n²)
#include <stdio.h>

int main()
{
    int arr[] = {23, 34, 31, 35, 76, 67, 11, 39}, i, j, current;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    for (i = 1; i < size; i++)
    {
        current = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }

    printf("\nSorted Array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted Array (Descending Order):\n");
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
