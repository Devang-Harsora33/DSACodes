// Binary Search Time Complexity = O(log n) ---> Sorted Elements

#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10];
    int j;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &j);

    for (int i = 0; i < j; i++)
    {
        printf("Enter data: ");
        scanf("%d", &arr[i]);
    }

    int size = j, target;

    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    int pos = binarySearch(arr, size, target);
    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element is found at %d position\n", pos + 1);

    return 0;
}
