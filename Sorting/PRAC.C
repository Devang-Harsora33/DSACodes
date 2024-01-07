#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10], n, i, temp;
    printf("Enter the number of elements to sort :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n Enter element: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}