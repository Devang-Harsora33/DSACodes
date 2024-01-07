// Fibonacci Search Time Complexity = O(log n) ---> Sorted Elements
// works on divide and conquer principle and divides the array into 1:2 ratio every time before comparing

#include <stdio.h>

int min(int, int);
int fibonacci_search(int[], int, int);

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int fibonacci_search(int arr[], int n, int key)
{
    int offset = -1;
    int Fm2 = 0;
    int Fm1 = 1;
    int Fm = Fm2 + Fm1;

    while (Fm < n)
    {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm2 + Fm1;
    }

    while (Fm > 1)
    {
        int i = min(offset + Fm2, n - 1);

        if (arr[i] < key)
        {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        }
        else if (arr[i] > key)
        {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        }
        else
            return i;
    }

    if (Fm1 && arr[offset + 1] == key)
        return offset + 1;
    return -1;
}

int main()
{
    int n, key, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to be searched: ");
    scanf("%d", &key);

    pos = fibonacci_search(arr, n, key);

    if (pos >= 0)
        printf("The element is found at index %d\n", pos + 1);
    else
        printf("Unsuccessful Search\n");

    return 0;
}