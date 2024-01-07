#include <stdio.h>

#define Size 10
int array[10];
int stack[Size], top = -1;

void push(int a)
{
    stack[++top] = a;
}

int pop()
{
    return stack[top--];
}

void reverse()
{

    int i = 0, length = 0;

    while (array[i++] != '\0')
    {
        length++;
    }
    for (i = 0; i < length; i++)
    {
        push(array[i]);
        printf("%d", array[i]);
    }
    printf("\n");
}

void display()
{

    int i = top;
    while (i != -1)
    {
        printf("%d ", stack[i]);
        i--;
    }
}

int main()
{

    int i = 0, j;
    printf("Enter size of array: ");
    scanf("%d", &j);
    printf("Enter elements: ");
    for (i = 0; i < j; i++)
    {
        scanf("%d", &array[i]);
    }

    reverse();
    display();

    return 0;
}